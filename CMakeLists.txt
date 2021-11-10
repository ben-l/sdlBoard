 # Set the minimum version of CMake that can be used
    # To find the cmake version run
    # $ cmake --version
    cmake_minimum_required(VERSION 3.5)

    # Set the project name
    project(Board)

    find_package(SDL2 REQUIRED)

    # Create a sources variable with a link to all cpp files to compile
	set(SOURCES 
			src/main.cpp
			src/Application.cpp
			src/Board.cpp
			src/Window.cpp
		)

    # Add an executable with the above sources
    add_executable(${PROJECT_NAME} ${SOURCES})

	target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

    # Set the directories that should be included in the build command for this target
    include_directories(src ${SDL2_INCLUDE_DIRS})
