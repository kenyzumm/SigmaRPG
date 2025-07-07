# =============================================================================
# SigmaRPG - Source CMakeLists.txt
# =============================================================================

# =============================================================================
# Source Files Organization
# =============================================================================

# Core engine files
set(CORE_SOURCES
    Game.cpp
    StateMachine.cpp
)

# State implementations
set(STATE_SOURCES
    SplashState.cpp
    MainMenuState.cpp
    GameState.cpp
)

# Game systems
set(SYSTEM_SOURCES
    AssetsManager.cpp
    InputManager.cpp
    Logger.cpp
)

# Game objects
set(GAMEOBJECT_SOURCES
    Player.cpp
    Movement.cpp
    Animation.cpp
)

# Main entry point
set(MAIN_SOURCE
    main.cpp
)

# Combine all sources
set(ALL_SOURCES
    ${MAIN_SOURCE}
    ${CORE_SOURCES}
    ${STATE_SOURCES}
    ${SYSTEM_SOURCES}
    ${GAMEOBJECT_SOURCES}
)

# =============================================================================
# Target Configuration
# =============================================================================

# Create executable target
add_executable(SigmaRPG ${ALL_SOURCES})

# =============================================================================
# Include Directories
# =============================================================================

# Use modern target_include_directories instead of include_directories
target_include_directories(SigmaRPG 
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

# =============================================================================
# Dependencies
# =============================================================================

# Link SFML libraries
target_link_libraries(SigmaRPG PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)

# =============================================================================
# Compiler Flags (Less Restrictive)
# =============================================================================

# Basic warning flags (not treating warnings as errors)
if(MSVC)
    target_compile_options(SigmaRPG PRIVATE
        /W3           # Warning level 3 (less strict than W4)
        /utf-8        # Enable UTF-8 source encoding
    )
else()
    target_compile_options(SigmaRPG PRIVATE
        -Wall         # Enable common warnings
        -Wextra       # Enable extra warnings
        -fPIC         # Position Independent Code
    )
endif()

# =============================================================================
# Build Information
# =============================================================================

# Print build information
message(STATUS "Building SigmaRPG executable")
message(STATUS "Source files: ${ALL_SOURCES}")
message(STATUS "Include directories: ${CMAKE_CURRENT_SOURCE_DIR}/../include")