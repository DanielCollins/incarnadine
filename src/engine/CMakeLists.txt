
include_directories(${INCARNADINE_SOURCE_DIR}/src/include)
include_directories(${INCARNADINE_SOURCE_DIR}/src/shared)

add_library(engine display.cpp object.cpp camera.cpp scene.cpp render.cpp input.cpp)

