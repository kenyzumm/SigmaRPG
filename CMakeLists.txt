cmake_minimum_required(VERSION 3.30)
project(SigmaRPG)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(SFML 3.0 COMPONENTS Graphics REQUIRED)

add_subdirectory(src)

target_link_libraries(SigmaRPG PRIVATE
    SFML::Graphics
)
