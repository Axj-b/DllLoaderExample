# CMakeLists.txt

# Define the minimum required version of CMake
cmake_minimum_required(VERSION 3.30)

get_filename_component(CURRENT_FOLDER_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${CURRENT_FOLDER_NAME} VERSION 1.0.0)


# Set the output directory for the build artifacts
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add your source files here
add_library(${CURRENT_FOLDER_NAME} SHARED
    ../../../../${CURRENT_FOLDER_NAME}/src/main.cpp
    ./cpu2.cpp
)

# Add any required include directories
target_include_directories(${CURRENT_FOLDER_NAME} PUBLIC
    include
)

# Add any required libraries
# target_link_libraries(MyDLL
#     lib1
#     lib2
# )

# Add any required compiler flags
# target_compile_options(MyDLL PRIVATE
#     -Wall
#     -Wextra
#     -pedantic
# )

# Add any required linker flags
# target_link_options(MyDLL PRIVATE
#     -Wl,--no-undefined
# )