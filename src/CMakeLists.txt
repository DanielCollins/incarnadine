
# There is no default install location for SDL on Windows, so allow
# the user to set a variable pointing to the SDL development files.
set(SDL_ROOT "" CACHE PATH "Location of SDL development files.")
if (SDL_ROOT)
	set(CMAKE_PREFIX_PATH ${SDL_ROOT})
endif()

Find_Package(OpenGL REQUIRED)
Find_Package(SDL REQUIRED)

if (NOT OPENGL_FOUND)
	message(FATAL_ERROR "OpenGL not found!")
endif()

if (NOT SDL_FOUND)
	message (FATAL_ERROR "SDL not found!" )
endif()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${SDL_INCLUDE_DIR})

add_subdirectory(engine)
add_subdirectory(test)

