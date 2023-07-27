cmake_minimum_required(VERSION 3.8)

project(Cloth)

add_subdirectory(imgui)

# Add source files
file(GLOB_RECURSE SOURCE_FILES_ 
	${CMAKE_SOURCE_DIR}/src/*.cpp)

add_library(cloth_lib STATIC ${SOURCE_FILES_})
target_include_directories(cloth_lib PUBLIC include shaders)
target_link_libraries(cloth_lib imgui)

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} cloth_lib)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)

# gtest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)
