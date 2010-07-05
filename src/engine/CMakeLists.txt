
include_directories(${INCARNADINE_SOURCE_DIR}/src/include)
include_directories(${INCARNADINE_SOURCE_DIR}/src/shared)

add_library(engine incarnadine.cpp display.cpp object.cpp camera.cpp scene.cpp render.cpp input.cpp triangle.cpp primitive.cpp vbo.cpp renderable.cpp config.cpp log.cpp)
target_link_libraries(engine ${OPENGL_LIBRARY} ${SDL_LIBRARY} ${SDLMAIN_LIBRARY})

