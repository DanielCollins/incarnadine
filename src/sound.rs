use std::path::Path;
use sdl2::*;
use sdl2;
use sdl2_mixer::{INIT_MP3, INIT_FLAC, INIT_MOD, INIT_FLUIDSYNTH, INIT_MODPLUG, INIT_OGG,
                 AUDIO_S16LSB};
use sdl2_mixer;

pub struct Sounds {
    pub jump: sdl2_mixer::Music,
    pub land: sdl2_mixer::Music,
    _a: sdl2::AudioSubsystem
}

impl Sounds {

    fn load_sound(name: &str) -> sdl2_mixer::Music {
        let base = "resources/sounds/".to_string();
        let filename = base + name;
        let path = Path::new(&filename);
        sdl2_mixer::Music::from_file(path).unwrap()
    }

    pub fn new() -> Self {
        let sdl = sdl2::init().unwrap();
        let audio = sdl.audio().unwrap();
        let _mixer_context = sdl2_mixer::init(INIT_MP3 |
                                              INIT_FLAC |
                                              INIT_MOD |
                                              INIT_FLUIDSYNTH |
                                              INIT_MODPLUG |
                                              INIT_OGG);
        let _ = sdl2_mixer::open_audio(44100, AUDIO_S16LSB, 2, 1024).unwrap();
        sdl2_mixer::allocate_channels(0);

        Sounds { _a: audio, // needs to stay live
                 jump: Self::load_sound("jump.wav"),
                 land: Self::load_sound("land.wav")}
    }
}
