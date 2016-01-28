#[macro_use]
extern crate glium;
extern crate time;
extern crate image;
extern crate sdl2;
extern crate sdl2_mixer;
mod shaders;
mod camera;
mod types;
mod wall;
mod floor;
mod teapot;
mod world;
mod sound;
mod skybox;
mod texture;

fn handle_resize(width: u32, height: u32, camera: &mut camera::Camera)
{
    camera.projection = camera::get_perspective((width, height));
}

fn window_center(panel: & glium::backend::glutin_backend::WinRef)
        -> (i32, i32) {
    let (ww, wh) = panel.get_outer_size().unwrap();
    return ((ww / 2) as i32, (wh / 2) as i32);
}

fn handle_inputs(window: &types::Display, camera: &mut camera::Camera) -> bool {
    let mut close: bool = false;
    for ev in window.poll_events() {
        match ev {
            glium::glutin::Event::Resized(w, h) =>
                handle_resize(w, h, camera),
            glium::glutin::Event::Closed => close = true,
            glium::glutin::Event::KeyboardInput(s, _, c) => 
                match (s, c) {
                    (_, Some(glium::glutin::VirtualKeyCode::Escape)) =>
                        { close = true; },

                    (glium::glutin::ElementState::Released,
                     Some(glium::glutin::VirtualKeyCode::W)) |  
                    (glium::glutin::ElementState::Released,
                     Some(glium::glutin::VirtualKeyCode::S)) =>
                        { camera.zmove = camera::Move::Null; },

                    (glium::glutin::ElementState::Released,
                     Some(glium::glutin::VirtualKeyCode::A)) |  
                    (glium::glutin::ElementState::Released,
                     Some(glium::glutin::VirtualKeyCode::D)) =>
                        { camera.xmove = camera::Move::Null; },

                    (glium::glutin::ElementState::Pressed,
                     Some(glium::glutin::VirtualKeyCode::W)) =>
                        { camera.zmove = camera::Move::Positive; },

                    (glium::glutin::ElementState::Pressed,
                     Some(glium::glutin::VirtualKeyCode::S)) =>
                        { camera.zmove = camera::Move::Negative; },

                    (glium::glutin::ElementState::Pressed,
                     Some(glium::glutin::VirtualKeyCode::D)) =>
                        { camera.xmove = camera::Move::Positive; },

                    (glium::glutin::ElementState::Pressed,
                     Some(glium::glutin::VirtualKeyCode::A)) =>
                        { camera.xmove = camera::Move::Negative; },

                    (glium::glutin::ElementState::Pressed,
                      Some(glium::glutin::VirtualKeyCode::Space)) =>
                        { camera.want_jump = true; },

                    (glium::glutin::ElementState::Released,
                      Some(glium::glutin::VirtualKeyCode::Space)) =>
                        { camera.want_jump = false; },


                    _ => ()

                },
            glium::glutin::Event::MouseMoved((x, y)) => {
                let panel = window.get_window().unwrap();
                let (cx, cy) = window_center(&panel);
                let dx: i32 = x - cx;
                let dy: i32 = y - cy;
                panel.set_cursor_position(cx, cy).unwrap();
                camera.a -= (dx as f32) * 0.0002;
                camera.b -= (dy as f32) * 0.0002;
                camera.b = camera.b.max(-std::f32::consts::FRAC_PI_2);
                camera.b = camera.b.min(std::f32::consts::FRAC_PI_2);
            }
            _ => ()
        }
    }
    return close;
}

fn get_window() -> types::Display {
    use glium::DisplayBuild;
    return glium::glutin::WindowBuilder::new()
                    .with_depth_buffer(24)
                    .with_title(format!("incarnadine"))
                    .build_glium().unwrap();
}

fn init_cursor(window: &types::Display) {
    let panel = window.get_window().unwrap();
    let (cx, cy) = window_center(&panel);
    panel.set_cursor_position(cx, cy).unwrap();
}

fn main() {
    let window = get_window();
    let library = shaders::ShaderLibrary::new(&window);
    let sounds = sound::Sounds::new();
    let mut camera = camera::Camera::new(&window, sounds);
    let world = world::World::new(&window);
    let mut last_tick = time::precise_time_ns();
    init_cursor(&window);
    loop {
        if handle_inputs(&window, &mut camera) {
            std::process::exit(0);
        }
        let now = time::precise_time_ns();
        let frame_time = now - last_tick;
        last_tick = now;
        camera.update_physics(frame_time);
        world.render(&camera, &library, &window);
    }
}
