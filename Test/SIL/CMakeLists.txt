# CMakeLists.txt

# Define the minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(MyProject VERSION 1.0.0)

# Set the output directory for the build artifacts
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files for the shared libraries
#add_library(cpu1 SHARED cpu1.cpp)
#add_library(cpu2 SHARED cpu2.cpp)
#add_library(cpu3 SHARED cpu3.cpp)

add_subdirectory(CPU1)
add_subdirectory(CPU2)

# Link the shared libraries to the executable target
add_executable(my_executable 
	main.cpp
	LibraryLoader.cpp
	LibraryLoader.h
)

#target_link_libraries(my_executable lib1 lib2 lib3)