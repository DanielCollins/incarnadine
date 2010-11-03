include_directories(${INCARNADINE_SOURCE_DIR}/src/include)

add_library(engine
            incarnadine.cpp
            display.cpp
            object.cpp
            camera.cpp
            scene.cpp
            render.cpp
            input.cpp
            staticm.cpp
            vbo.cpp
            visible.cpp
            clock.cpp
            md2.cpp
            texture.cpp
            widget.cpp
            font.cpp
            obj.cpp
            label.cpp
            ${INCARNADINE_SOURCE_DIR}/src/external/glew.c)

target_link_libraries(engine ${OPENGL_LIBRARY} ${SDL_LIBRARY} ${SDLMAIN_LIBRARY} ${SDLTTF_LIBRARY} ${SDLIMAGE_LIBRARY})
