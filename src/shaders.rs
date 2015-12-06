use glium;

pub struct ShaderLibrary {
    pub lit_colour: glium::Program,
    pub lit_texture: glium::Program,
    pub skybox: glium::Program
}

fn get_program(window: &glium::backend::glutin_backend::GlutinFacade) ->
   glium::Program {
    let vertex_shader_src = r#"
        #version 140
        in vec3 position;
        in vec3 normal;
        out vec3 v_normal;
        out vec3 v_position;
        uniform mat4 projection;
        uniform mat4 view;
        uniform mat4 model;
        void main() {
            mat4 modelview = view * model;
            vec4 vert_p = modelview * vec4(position, 1.0);
            v_normal = mat3(modelview) * normal;
            v_position = vec3(vert_p) / vert_p.w;
            gl_Position = projection * modelview * vec4(position, 1.0);
        }
    "#;

    let fragment_shader_src = r#"
        #version 140
        in vec3 v_normal;
        in vec3 v_position;
        out vec4 colour;
        uniform vec3 u_light;
        const vec3 ambient_color = vec3(0.1, 0.0, 0.0);
        const vec3 diffuse_color = vec3(0.5, 0.0, 0.0);
        const vec3 specular_color = vec3(1.0, 1.0, 1.0);
        const float screen_gamma = 1.0;
        const vec3 gamma_correction = vec3(1.0 / screen_gamma);
        const float shininess = 14;
        void main() {
            vec3 normal = normalize(v_normal);
            vec3 light = normalize(u_light);
            float brightness = dot(normal, light);
            float diffuse = max(brightness, 0.0);
            vec3 camera_dir = normalize(-v_position);
            vec3 half_direction = normalize(light + camera_dir);
            float specular_angle = max(dot(half_direction, normal), 0.0);
            float specular = pow(specular_angle, shininess);
            vec3 linear_colour = ambient_color +
                                 diffuse * diffuse_color +
                                 specular * specular_color;
            vec3 gamma_corrected = pow(linear_colour, gamma_correction);
            colour = vec4(gamma_corrected, 1.0);
        }
    "#;

    return glium::Program::from_source(window, vertex_shader_src,
                                       fragment_shader_src, None).unwrap();
}


fn get_tprogram(window: &glium::backend::glutin_backend::GlutinFacade) ->
   glium::Program {
    let vertex_shader_src = r#"
        #version 140
        in vec3 position;
        in vec3 normal;
        in vec2 tex_coords;
        out vec3 v_normal;
        out vec3 v_position;
        out vec2 v_tex_coords;
        uniform mat4 projection;
        uniform mat4 view;
        uniform mat4 model;
        void main() {
            v_tex_coords = tex_coords;
            mat4 modelview = view * model;
            vec4 vert_p = modelview * vec4(position, 1.0);
            v_normal = mat3(modelview) * normal;
            v_position = vec3(vert_p) / vert_p.w;
            gl_Position = projection * modelview * vec4(position, 1.0);
        }
    "#;

    let fragment_shader_src = r#"
        #version 140
        in vec3 v_normal;
        in vec3 v_position;
        in vec2 v_tex_coords;
        out vec4 colour;
        uniform vec3 u_light;
        uniform sampler2D diffuse_tex;
        uniform sampler2D normal_tex;
        const vec3 specular_color = vec3(1.0, 1.0, 1.0);
        const float screen_gamma = 1.0;
        const vec3 gamma_correction = vec3(1.0 / screen_gamma);
        const float shininess = 14;
        mat3 cotangent_frame(vec3 normal, vec3 pos, vec2 uv) {
            vec3 dp1 = dFdx(pos);
            vec3 dp2 = dFdy(pos);
            vec2 duv1 = dFdx(uv);
            vec2 duv2 = dFdy(uv);
            vec3 dp2perp = cross(dp2, normal);
            vec3 dp1perp = cross(normal, dp1);
            vec3 T = dp2perp * duv1.x + dp1perp * duv2.x;
            vec3 B = dp2perp * duv1.y + dp1perp * duv2.y;
            float invmax = inversesqrt(max(dot(T, T), dot(B, B)));
            return mat3(T * invmax, B * invmax, normal);
        }
        void main() {
            vec3 diffuse_color = texture(diffuse_tex, v_tex_coords).rgb;
            vec3 normal_map = texture(normal_tex, v_tex_coords).rgb;
            vec3 ambient_color = diffuse_color * 0.2;
            mat3 tbn = cotangent_frame(v_normal, v_position, v_tex_coords);
            vec3 normal = normalize(tbn * -(normal_map * 2.0 - 1.0));
            vec3 light = normalize(u_light);
            float brightness = dot(normal, light);
            float diffuse = max(brightness, 0.0);
            vec3 camera_dir = normalize(-v_position);
            vec3 half_direction = normalize(light + camera_dir);
            float specular_angle = max(dot(half_direction, normal), 0.0);
            float specular = pow(specular_angle, shininess);
            vec3 linear_colour = ambient_color +
                                 diffuse * diffuse_color +
                                 specular * specular_color;
            vec3 gamma_corrected = pow(linear_colour, gamma_correction);
            colour = vec4(gamma_corrected, 1.0);
        }
    "#;

    return glium::Program::from_source(window, vertex_shader_src,
                                       fragment_shader_src, None).unwrap();
}


fn get_skybox(window: &glium::backend::glutin_backend::GlutinFacade) ->
   glium::Program {

    let vertex_shader_src = r#"
        #version 330
        in vec3 position;
        in vec2 tex_coords;
        smooth out vec3 eye_direction;
        uniform mat4 projection;
        uniform mat4 view;
        void main() {
            mat4 inv_projection = inverse(projection);
            // mat3 throws out position. transpose == inverse since no shearing
            mat3 inv_view = transpose(mat3(view));
            vec3 unprojected = (inv_projection * vec4(position, 1.0)).xyz;
            eye_direction = inv_view * unprojected;
            gl_Position = vec4(position, 1.0);
        }
    "#;

    let fragment_shader_src = r#"
        #version 330
        smooth in vec3 eye_direction;
        out vec4 colour;
        // TODO: should be samplerCube type
        uniform sampler2D diffuse_tex;
        void main() {
            // TODO: dont need vec2() if using samplerCUbe
            //colour = texture(diffuse_tex, vec2(eye_direction));
            colour = vec4(eye_direction, 1.0);
        }
    "#;

    return glium::Program::from_source(window, vertex_shader_src,
                                       fragment_shader_src, None).unwrap();
}



impl ShaderLibrary {

    pub fn new(window: &glium::backend::glutin_backend::GlutinFacade) ->
        ShaderLibrary {
        ShaderLibrary {
            lit_colour: get_program(window),
            lit_texture: get_tprogram(window),
            skybox: get_skybox(window)
        }
    }

}
