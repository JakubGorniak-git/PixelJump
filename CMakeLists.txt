cmake_minimum_required(VERSION 3.27)
project(project)

set(CMAKE_CXX_STANDARD 17)

# Set the path to SFML
set(SFML_DIR "C:/SFML/lib/cmake/SFML")

include_directories("C:/SFML/include")
# Find SFML (accept any version)
find_package(SFML REQUIRED COMPONENTS system window graphics network audio)

# Add the executable
add_executable(project main.cpp
        player.h
        player.cpp)

# Link SFML libraries
target_link_libraries(project sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

#testujemy wkp