
Find_Package(OpenGL REQUIRED)
Find_Package(SDL REQUIRED)

if (NOT OPENGL_FOUND)
	message(FATAL_ERROR "OpenGL not found!")
endif()

if (NOT SDL_FOUND)
	message (FATAL_ERROR "SDL not found!" )
endif()

include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${SDL_INCLUDE_DIR})

add_subdirectory(engine)
add_subdirectory(test)

