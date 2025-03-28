cmake_minimum_required(VERSION 3.22)
project(TNAP)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE SOURCES src/*.cpp)
<<<<<<< HEAD
add_executable(
TNAP ${SOURCES}
src/buttons/menu_buttont.cpp
src/telephone.cpp

)
=======
add_executable(TNAP ${SOURCES})
>>>>>>> 8fca2d67e76a609a4a68357eef7f2ec93000d72c
target_compile_features(TNAP PRIVATE cxx_std_17)
target_link_libraries(TNAP PRIVATE SFML::Graphics SFML::Audio)
