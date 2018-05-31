cmake_minimum_required(VERSION 3.10)
project(3dShowcase C)

set(CMAKE_C_STANDARD 99)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(3dShowcase src/main.c src/shader.c src/camera.c src/glad.c)
target_link_libraries(3dShowcase -lglfw -lm -ldl)
