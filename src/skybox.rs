use glium;
use types;
use camera;
use shaders;
use texture;

#[derive(Copy, Clone)]
struct Vertex {
    position: [f32; 3],
    tex_coords: [f32; 2]
}

implement_vertex!(Vertex, position, tex_coords);

pub struct Skybox {
    buffer: glium::VertexBuffer<Vertex>,
    diffuse_texture: glium::texture::SrgbTexture2d
}

impl Skybox {

    pub fn new(window: &types::Display) -> Self {
        let material = "wall".to_string();
        let diffuse_texture = texture::load(window, &material);
        //let lol = glium::texture::SrgbCubemap(window, image);
        let buffer = glium::vertex::VertexBuffer::new(window, &[
            Vertex { position: [-1.0,  1.0, 0.0],
                     tex_coords: [0.0, 1.0] },
            Vertex { position: [ 1.0,  1.0, 0.0],
                     tex_coords: [1.0, 1.0] },
            Vertex { position: [-1.0, -1.0, 0.0],
                     tex_coords: [0.0, 0.0] },
            Vertex { position: [ 1.0, -1.0, 0.0],
                     tex_coords: [1.0, 0.0] },
        ]).unwrap();


        Skybox {
            buffer: buffer,
            diffuse_texture: diffuse_texture
        }
    }

    pub fn render(self: &Self, frame_buffer: &mut glium::Frame,
                  camera: &camera::Camera, library: &shaders::ShaderLibrary) {
        use glium::Surface;
        use glium::DrawParameters;

        let strip = glium::index::PrimitiveType::TriangleStrip;
        let params = glium::DrawParameters {
            depth: glium::Depth {
                test: glium::draw_parameters::DepthTest::Overwrite,
                write: false,
                .. Default::default()
            },
            .. Default::default()
        };

        let uniforms = uniform! {
            projection: camera.projection,
            view: camera.get_view(),
            diffuse_tex: &self.diffuse_texture,
        };

        frame_buffer.draw(&self.buffer, &glium::index::NoIndices(strip),
                          &library.skybox,
                          &uniforms, &params).unwrap();
    }
}
