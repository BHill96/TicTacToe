# stop if CMake version is below 3.0
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# project name and supported languages
#set(CMAKE_C_COMPILER "/usr/local/bin/x86_64-apple-darwin20-gcc-11")
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
project(TicTacToe VERSION 1.0 LANGUAGES CXX)

# require C++11
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)


# specify where to place binaries and libraries
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

# contains a workaround for macOS
include(cmake/arch.cmake)
macos_workaround()

include(cmake/version.cmake)
generate_version_h()

# process src/CMakeLists.txt
add_subdirectory(src)

# enable testing
enable_testing()

# process test/CMakeLists.txt
add_subdirectory(test)

# contains cpack code
include(cmake/packaging.cmake)