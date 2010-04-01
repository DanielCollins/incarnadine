
include_directories(${INCARNADINE_SOURCE_DIR}/src/engine)
include_directories(${INCARNADINE_SOURCE_DIR}/src/shared)
include_directories(${INCARNADINE_SOURCE_DIR}/src/include)

add_executable(test test.cpp)
target_link_libraries(test engine)

