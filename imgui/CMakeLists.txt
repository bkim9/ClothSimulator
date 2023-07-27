cmake_minimum_required(VERSION 3.8)

# OpenGL
find_package(glfw3 3.2 REQUIRED)
find_package(OpenGL REQUIRED)
FIND_LiBRARY(OpenGL_LIBRARY OpenGL)

# Add source files
file(GLOB_RECURSE IMGUI_SOURCE_FILES 
	src/*.cpp)

add_library(imgui ${IMGUI_SOURCE_FILES} )
target_compile_features(imgui PUBLIC cxx_std_11)
target_link_libraries(imgui glfw ${OpenGL_LIBRARY})
target_include_directories(imgui PUBLIC include)
target_link_libraries(imgui
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
    )


include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

# glfw test
enable_testing()
add_executable( testgui
                guitest.cpp)

target_include_directories(testgui PUBLIC include)

target_link_libraries(testgui PRIVATE imgui GTest::gtest_main)
target_compile_options(testgui PRIVATE ${GTEST_CFLAGS})


add_test(first_and_only_test testgui)
include(GoogleTest)


    