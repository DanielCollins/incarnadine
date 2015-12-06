use types;
use teapot;
use camera;
use wall;
use floor;
use skybox;
use shaders;

pub struct World {
    teapot: teapot::Teapot,
    wall: wall::Wall,
    floor: floor::Floor,
    skybox: skybox:: Skybox
}

impl World {

    pub fn new(window: &types::Display) -> Self {
        World { teapot: teapot::Teapot::new(window),
                wall: wall::Wall::new(window),
                floor: floor::Floor::new(window),
                skybox: skybox::Skybox::new(window) }
                
    }

    pub fn render(self: &Self, camera: &camera::Camera,
                  library: &shaders::ShaderLibrary, window: &types::Display) {
        use glium::Surface;
        let mut frame_buffer = window.draw();
        frame_buffer.clear_color_and_depth((1.0, 1.0, 1.0, 1.0), 1.0);
        self.skybox.render(&mut frame_buffer, &camera, library);
        self.wall.render(&mut frame_buffer, &camera, library);
        self.floor.render(&mut frame_buffer, &camera, library);
        self.teapot.render(&mut frame_buffer, &camera, library); 
        frame_buffer.finish().unwrap();
    }
}
