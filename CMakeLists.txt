# =============================================================================
# SigmaRPG - Main CMakeLists.txt
# =============================================================================

# Minimum CMake version required
cmake_minimum_required(VERSION 3.30)

# Project configuration
project(SigmaRPG 
    VERSION 1.0.0
    DESCRIPTION "A 2D RPG game engine built with C++ and SFML"
    LANGUAGES CXX
)

# =============================================================================
# Compiler Configuration
# =============================================================================

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set default build type if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# =============================================================================
# Dependencies
# =============================================================================

# Find SFML
find_package(SFML 3.0 COMPONENTS 
    Graphics 
    Window 
    System 
    REQUIRED
)

# =============================================================================
# Project Structure
# =============================================================================

# Add subdirectories
add_subdirectory(src)

# =============================================================================
# Installation
# =============================================================================

# Install executable
install(TARGETS SigmaRPG
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

# Install resources
install(DIRECTORY resources/
    DESTINATION share/SigmaRPG/resources
    FILES_MATCHING PATTERN "*.png" PATTERN "*.jpg" PATTERN "*.wav" PATTERN "*.ogg"
)

# =============================================================================
# Print Configuration Summary
# =============================================================================

message(STATUS "=== SigmaRPG Configuration ===")
message(STATUS "Version: ${PROJECT_VERSION}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "SFML version: ${SFML_VERSION}")
message(STATUS "================================")
