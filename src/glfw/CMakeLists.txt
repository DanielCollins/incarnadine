
find_package(X11 REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${X11_INCLUDE_DIRS})
include_directories(${OPENGL_INCLUDE_DIRS})
set(LIBS ${LIBS} ${OPENGL_LIBRARIES} ${X11_LIBRARIES})

include_directories(${INCARNADINE_SOURCE_DIR}/src/glfw/include)
include_directories(${INCARNADINE_SOURCE_DIR}/src/glfw/lib)
include_directories(${INCARNADINE_SOURCE_DIR}/src/glfw/lib/x11)

add_library(glfw STATIC
	${INCARNADINE_SOURCE_DIR}/src/glfw/lib/enable.c
	${INCARNADINE_SOURCE_DIR}/src/glfw/lib/fullscreen.c
	${INCARNADINE_SOURCE_DIR}/src/glfw/lib/glext.c
	${INCARNADINE_SOURCE_DIR}/src/glfw/lib/image.c
	${INCARNADINE_SOURCE_DIR}/src/glfw/lib/init.c
	${INCARNADINE_SOURCE_DIR}/src/glfw/lib/input.c
	${INCARNADINE_SOURCE_DIR}/src/glfw/lib/internal.h
	${INCARNADINE_SOURCE_DIR}/src/glfw/lib/joystick.c
	${INCARNADINE_SOURCE_DIR}/src/glfw/lib/stream.c
	${INCARNADINE_SOURCE_DIR}/src/glfw/lib/tga.c
	${INCARNADINE_SOURCE_DIR}/src/glfw/lib/thread.c
	${INCARNADINE_SOURCE_DIR}/src/glfw/lib/time.c
	${INCARNADINE_SOURCE_DIR}/src/glfw/lib/window.c
	${INCARNADINE_SOURCE_DIR}/src/glfw/lib/x11/x11_enable.c
	${INCARNADINE_SOURCE_DIR}/src/glfw/lib/x11/x11_fullscreen.c
	${INCARNADINE_SOURCE_DIR}/src/glfw/lib/x11/x11_glext.c
	${INCARNADINE_SOURCE_DIR}/src/glfw/lib/x11/x11_init.c
	${INCARNADINE_SOURCE_DIR}/src/glfw/lib/x11/x11_joystick.c
	${INCARNADINE_SOURCE_DIR}/src/glfw/lib/x11/x11_keysym2unicode.c
	${INCARNADINE_SOURCE_DIR}/src/glfw/lib/x11/x11_thread.c
	${INCARNADINE_SOURCE_DIR}/src/glfw/lib/x11/x11_time.c
	${INCARNADINE_SOURCE_DIR}/src/glfw/lib/x11/x11_window.c
)

target_link_libraries(glfw ${LIBS})

# ${INCARNADINE_SOURCE_DIR}/src/glfw/lib/x11/*.c)

