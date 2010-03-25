cmake_minimum_required(VERSION 2.6)
project(INCARNADINE)

add_subdirectory(src)

Find_Package(SDL REQUIRED)


if ( NOT SDL_FOUND )
   message ( FATAL_ERROR "SDL not found!" )
endif ( NOT SDL_FOUND )

