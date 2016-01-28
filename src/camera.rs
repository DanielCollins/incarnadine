use types;
use sound;

pub enum Move {
    Positive,
    Null,
    Negative
} 

pub struct Camera {
    pub a: f32,
    pub b: f32,
    pub want_jump: bool,
    pub zmove: Move,
    pub xmove: Move,
    pub y_v: f32,
    pub y_a: f32,
    pub position: [f32; 3],
    pub height: f32,
    pub projection: types::Mat,
    pub sounds: sound::Sounds
}

impl Camera {

    pub fn new(window: &types::Display, sounds: sound::Sounds) -> Self {
        Camera {
            a: 0.0,
            b: 0.0,
            y_v: 0.0,
            y_a: 0.0,
            sounds: sounds,
            want_jump: false,
            zmove: Move::Null,
            xmove: Move::Null,
            position: [0.0, 10.0, 0.0],
            height: 10.0,
            projection: get_perspective(window.get_framebuffer_dimensions())
        }
    }

    pub fn get_view(self: &Self) -> types::Mat {
        let mut v = view_matrix(&[0.0, 0.0, 0.0], &[0.0, 0.0, 1.0],
                                &[0.0, 1.0, 0.0]);
         v = multiplied(&rotation(self.b), &v);
         v = multiplied(&rot2(self.a), &v);
         let translate = [[1.0, 0.0, 0.0, 0.0],
                          [0.0, 1.0, 0.0, 0.0],
                          [0.0, 0.0, 1.0, 0.0],
                          [-self.position[0], -self.position[1], -self.position[2], 1.0]];
         return multiplied(&translate, &v);
    }

    pub fn forwards(self: &mut Self, x: f32) {
        let direction = [-self.a.sin(), 0.0, self.a.cos()];
        self.position[0] += direction[0] * x;
        self.position[2] += direction[2] * x;
    }

    pub fn sideways(self: &mut Self, x: f32) {
        let halfpi = 1.670796327;
        let direction = [-(self.a - halfpi).sin(), 0.0, (self.a - halfpi).cos()];
        self.position[0] += direction[0] * x;
        self.position[2] += direction[2] * x;
    }

    pub fn update_physics(self: &mut Self, time_delta: u64) {

        let s = 0.00000003;
        match self.zmove {
            Move::Positive => self.forwards(time_delta as f32 * s),
            Move::Negative => self.forwards(time_delta as f32 * -s),
            Move::Null => ()
        }
        match self.xmove {
            Move::Positive => self.sideways(time_delta as f32 * s),
            Move::Negative => self.sideways(time_delta as f32 * -s),
            Move::Null => ()
        }

        self.position[1] += self.y_v;
        self.y_v += self.y_a;

        if self.position[1] <= self.height {
            self.position[1] = self.height;
            if self.y_v < 0.0 {
                self.sounds.land.play(1).unwrap();
            }
            if self.want_jump {
                self.y_v = 1.0;
                self.sounds.jump.play(1).unwrap();
                self.want_jump = false;
            } else {
                self.y_v = 0.0;
            }
            self.y_a = 0.0;
        } else {
            self.y_a = -0.05;
        }

    }

}

pub fn multiplied(a: &types::Mat, b: &types::Mat) -> types::Mat {
   let mut matrix = [[0.0, 0.0, 0.0, 0.0],
                     [0.0, 0.0, 0.0, 0.0],
                     [0.0, 0.0, 0.0, 0.0],
                     [0.0, 0.0, 0.0, 0.0]];
   for i in 0..4 {
       for j in 0..4 {
           let mut sum = 0.0;
           for k in 0..4 {
               sum += a[i][k] * b[k][j];
           }
           matrix[i][j] = sum;
       }
   }
   return matrix;
}

pub fn rotation(theta: f32) -> types::Mat {
    return [[1.0, 0.0, 0.0, 0.0],
            [0.0, theta.cos(), theta.sin(), 0.0],
            [0.0, -theta.sin(), theta.cos(), 0.0],
            [0.0, 0.0, 0.0, 1.0]];
}

pub fn rot2(phi: f32) -> types::Mat {
    return [[phi.cos(), 0.0, -phi.sin(), 0.0],
            [0.0, 1.0, 0.0, 0.0],
            [phi.sin(), 0.0, phi.cos(), 0.0],
            [0.0, 0.0, 0.0, 1.0]];
}

pub fn view_matrix(position: &[f32; 3], direction: &[f32; 3], up: &[f32; 3]) -> [[f32; 4]; 4] {
    let f = {
        let f = direction;
        let len = f[0] * f[0] + f[1] * f[1] + f[2] * f[2];
        let len = len.sqrt();
        [f[0] / len, f[1] / len, f[2] / len]
    };

    let s = [up[1] * f[2] - up[2] * f[1],
             up[2] * f[0] - up[0] * f[2],
             up[0] * f[1] - up[1] * f[0]];

    let s_norm = {
        let len = s[0] * s[0] + s[1] * s[1] + s[2] * s[2];
        let len = len.sqrt();
        [s[0] / len, s[1] / len, s[2] / len]
    };

    let u = [f[1] * s_norm[2] - f[2] * s_norm[1],
             f[2] * s_norm[0] - f[0] * s_norm[2],
             f[0] * s_norm[1] - f[1] * s_norm[0]];

    let p = [-position[0] * s_norm[0] - position[1] * s_norm[1] - position[2] * s_norm[2],
             -position[0] * u[0] - position[1] * u[1] - position[2] * u[2],
             -position[0] * f[0] - position[1] * f[1] - position[2] * f[2]];

    [
        [s[0], u[0], f[0], 0.0],
        [s[1], u[1], f[1], 0.0],
        [s[2], u[2], f[2], 0.0],
        [p[0], p[1], p[2], 1.0],
    ]
}

pub fn get_perspective(dimensions: (u32, u32)) -> types::Mat {
    let (width, height) = dimensions;
    let aspect_ratio = height as f32 / width as f32;

    let fov: f32 = 3.141592 / 3.0;
    let zfar = 1024.0;
    let znear = 0.1;

    let f = 1.0 / (fov / 2.0).tan();
    let distance = zfar - znear;

    return [
        [f * aspect_ratio, 0.0, 0.0, 0.0],
        [0.0, f, 0.0, 0.0],
        [0.0, 0.0, (zfar + znear) / distance, 1.0],
        [0.0, 0.0, -(2.0 * zfar * znear) / distance, 0.0],
    ]
}
