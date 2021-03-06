cmake_minimum_required(VERSION 3.6)

project(loopman)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -pedantic-errors -Wall -Werror -Wextra")

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS src/*.h)

if (EMSCRIPTEN)
    set(PLATFORM Web)
    set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
    set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
    set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE BOTH)
    set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

    add_definitions(-DPLATFORM_WEB)
    add_definitions(-DUSE_WASM)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --bind --memory-init-file 0 -s INITIAL_MEMORY=64MB -s SAFE_HEAP=1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_GLFW=3 -s USE_WEBGL2=1 -s FORCE_FILESYSTEM=1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s WASM=1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s ASSERTIONS=1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --use-preload-plugins")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --embed-file assets@/")
    set(CMAKE_EXECUTABLE_SUFFIX ".js")

    file(COPY assets DESTINATION ${CMAKE_BINARY_DIR}/)
    file(COPY assets/index.html DESTINATION ${CMAKE_BINARY_DIR}/)
else ()
    file(COPY assets/ DESTINATION ${CMAKE_BINARY_DIR})
endif ()

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

add_subdirectory(vendor/raylib)

target_include_directories(${PROJECT_NAME} PUBLIC SYSTEM vendor/raylib/src)
target_link_libraries(${PROJECT_NAME} raylib)
