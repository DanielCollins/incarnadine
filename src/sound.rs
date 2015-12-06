use rfmod;

pub struct Sounds {
    pub fmod: rfmod::Sys,
    pub jump: rfmod::Sound,
    pub land: rfmod::Sound
}

impl Sounds {
    pub fn new() -> Self {
        let fmod = rfmod::Sys::new().unwrap();
        fmod.init();
        Sounds { land: fmod.create_sound("resources/sounds/land.wav", None,
                                         None).unwrap(),
                 jump: fmod.create_sound("resources/sounds/jump.wav", None,
                                         None).unwrap(),
                 fmod: fmod }        // needs to stay in scope
    }
}
