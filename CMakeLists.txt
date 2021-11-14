# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# Set the project name
project(Board)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(src ${sdl2_include_dirs} ${SDL2_IMAGE_INCLUDE_DIRS})

# Create a sources variable with a link to all cpp files to compile
set(SOURCES 
		src/main.cpp
		src/Application.cpp
		src/Board.cpp
		src/Window.cpp
	)

# Add an executable with the above sources
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
