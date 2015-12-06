use glium;

#[derive(Copy, Clone)]
struct Vertex {
    position: [f32; 2],
}

implement_vertex!(Vertex, position);

pub type Display = glium::backend::glutin_backend::GlutinFacade;
pub type Mat = [[f32; 4]; 4];

