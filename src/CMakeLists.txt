set(SOURCES
        main.cpp
        StateMachine.cpp
        AssetsManager.cpp
        Logger.cpp
        InputManager.cpp
        Game.cpp
        SplashState.cpp
        MainMenuState.cpp
        GameState.cpp
)

add_executable(SigmaRPG ${SOURCES})

target_include_directories(SigmaRPG PRIVATE ${PROJECT_SOURCE_DIR}/include)