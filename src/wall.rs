use glium;
use types;
use camera;
use shaders;
use texture;

#[derive(Copy, Clone)]
struct Vertex {
    position: [f32; 3],
    normal: [f32; 3],
    tex_coords: [f32; 2]
}

implement_vertex!(Vertex, position, normal, tex_coords);

pub struct Wall {
    matrix: types::Mat,
    buffer: glium::VertexBuffer<Vertex>,
    diffuse_texture: glium::texture::SrgbTexture2d,
    normal_map: glium::texture::texture2d::Texture2d
}

impl Wall {

    pub fn new(window: &types::Display) -> Self {
        let material = "wall".to_string();
        let diffuse_texture = texture::load(window, &material);
        let normal_map = texture::load_normal(window, &material);
        let buffer = glium::vertex::VertexBuffer::new(window, &[
            Vertex { position: [-1.0,  1.0, 0.0],
                     normal: [0.0, 0.0, -1.0],
                     tex_coords: [0.0, 1.0] },
            Vertex { position: [ 1.0,  1.0, 0.0],
                     normal: [0.0, 0.0, -1.0],
                     tex_coords: [1.0, 1.0] },
            Vertex { position: [-1.0, -1.0, 0.0],
                     normal: [0.0, 0.0, -1.0],
                     tex_coords: [0.0, 0.0] },
            Vertex { position: [ 1.0, -1.0, 0.0],
                     normal: [0.0, 0.0, -1.0],
                     tex_coords: [1.0, 0.0] },
        ]).unwrap();


        Wall {
            buffer: buffer,
            diffuse_texture: diffuse_texture,
            normal_map: normal_map,
            matrix: [
                [10.01, 0.0, 0.0, 0.0],
                [0.0, 10.01, 0.0, 0.0],
                [0.0, 0.0, 10.01, 0.0],
                [0.0 , 10.0, 10.0, 1.0f32]
            ]
        }
    }

    pub fn render(self: &Self, frame_buffer: &mut glium::Frame,
                  camera: &camera::Camera, library: &shaders::ShaderLibrary) {
        use glium::Surface;
        use glium::DrawParameters;

        let strip = glium::index::PrimitiveType::TriangleStrip;
        let params = glium::DrawParameters {
            depth: glium::Depth {
                test: glium::draw_parameters::DepthTest::IfLess,
                write: true,
                .. Default::default()
            },
            .. Default::default()
        };

        let light = [-1.0, 0.4, 0.9f32];

        let uniforms = uniform! {
            model: self.matrix,
            projection: camera.projection,
            view: camera.get_view(),
            u_light: light,
            diffuse_tex: &self.diffuse_texture,
            normal_tex: &self.normal_map
        };

        frame_buffer.draw(&self.buffer, &glium::index::NoIndices(strip),
                          &library.lit_texture,
                          &uniforms, &params).unwrap();
    }
}
