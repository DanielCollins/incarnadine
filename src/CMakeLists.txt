
# There is no default install location for SDL on Windows, so allow
# the user to set a variable pointing to the SDL development files.
set(SDL_ROOT "" CACHE PATH "Location of SDL development files.")
set(SDLTTF_ROOT "" CACHE PATH "Location of SDL_ttf development files.")
set(SDLIMAGE_ROOT "" CACHE PATH "Location of SDL_image development files.")
if (SDL_ROOT)
	set(CMAKE_PREFIX_PATH ${SDL_ROOT})
endif()
if (SDLTTF_ROOT)
	set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${SDLTTF_ROOT})
endif()
if (SDLIMAGE_ROOT)
	set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${SDLIMAGE_ROOT})
endif()

Find_Package(OpenGL REQUIRED)
Find_Package(SDL REQUIRED)
Find_Package(SDL_ttf REQUIRED)
Find_Package(SDL_image REQUIRED)
Find_Package(SDL_mixer REQUIRED)

if (NOT OPENGL_FOUND)
	message(FATAL_ERROR "OpenGL not found!")
endif()

if (NOT SDL_FOUND)
	message (FATAL_ERROR "SDL not found!" )
endif()

if (NOT SDLTTF_FOUND)
	message (FATAL_ERROR "SDL_ttf not found!")
endif()

if (NOT SDLIMAGE_FOUND)
	message (FATAL_ERROR "SDL_image not found!")
endif()

if (NOT SDLMIXER_FOUND)
	message (FATAL_ERROR "SDL_mixer not found!")
endif()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${SDL_INCLUDE_DIR})
include_directories(${SDLTTF_INCLUDE_DIR})
include_directories(${SDLIMAGE_INCLUDE_DIR})
include_directories(${SDLMIXER_INCLUDE_DIR})

add_subdirectory(incarnadine)
add_subdirectory(examples)

