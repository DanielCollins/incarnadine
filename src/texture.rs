use glium;
use image;
use types;
use std::fs::File;

pub fn load(window: &types::Display, material: &String) -> glium::texture::SrgbTexture2d {
   let path = "resources/materials/".to_string() + material + &"/texture.jpg".to_string();
   let byte_stream = File::open(path).unwrap();
   let image = image::load(byte_stream, image::JPEG).unwrap().to_rgba();
   let dimensions = image.dimensions();
   let raw_image = image.into_raw();
   let glium_image = glium::texture::RawImage2d::from_raw_rgba_reversed(raw_image, dimensions);
   glium::texture::SrgbTexture2d::new(window, glium_image).unwrap()
}

pub fn load_normal(window: &types::Display, material: &String) -> glium::texture::Texture2d {
   let path = "resources/materials/".to_string() + material + &"/normals.png".to_string();
   let byte_stream = File::open(path).unwrap();
   let image = image::load(byte_stream, image::PNG).unwrap().to_rgba();
   let dimensions = image.dimensions();
   let raw_image = image.into_raw();
   let glium_image = glium::texture::RawImage2d::from_raw_rgba_reversed(raw_image, dimensions);
   glium::texture::Texture2d::new(window, glium_image).unwrap()
}
