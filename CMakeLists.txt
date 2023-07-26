cmake_minimum_required(VERSION 3.2)

project(Cloth)

set(PROJECT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(PROJECT_SHADER_DIR ${CMAKE_SOURCE_DIR}/shaders)

# Add source files
file(GLOB_RECURSE SOURCE_FILES_ 
	${CMAKE_SOURCE_DIR}/src/*.cpp)

# Add header files
file(GLOB_RECURSE HEADER_FILES_
	${CMAKE_SOURCE_DIR}/include/*.h)

# OpenGL
find_package(OpenGL REQUIRED)
find_package(glfw3 3.2 REQUIRED)
FIND_LiBRARY(OpenGL_LIBRARY OpenGL)


add_executable(${PROJECT_NAME} ${SOURCE_FILES_} ${HEADER_FILES_})
include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_INCLUDE_DIR} ${PROJECT_SHADER_DIR})
target_link_libraries(${PROJECT_NAME} glfw ${OpenGL_LIBRARY})