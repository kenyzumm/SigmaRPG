# Sigma RPG

A 2D RPG game engine built with C++ and SFML, featuring a state-based architecture with smooth player movement, animations, and asset management.

## 🎮 Features

- **State Machine Architecture**: Clean separation of game states (Splash, Main Menu, Game)
- **Smooth Player Movement**: Grid-based movement system with interpolation
- **Sprite Animation**: Multi-directional character animations
- **Asset Management**: Centralized texture and font loading system
- **Input Management**: Responsive input handling
- **Logging System**: Comprehensive logging for debugging
- **Modern C++**: Built with C++20 standards

## 🏗️ Architecture

### Core Components

- **Game**: Main game loop and window management
- **StateMachine**: Manages different game states (Splash, Main Menu, Game)
- **Player**: Character with movement and animation capabilities
- **Movement**: Grid-based movement system with smooth interpolation
- **Animation**: Sprite sheet animation system
- **AssetsManager**: Centralized asset loading and management
- **InputManager**: Input handling and event processing
- **Logger**: Logging system for debugging and monitoring

### State System

The game uses a state machine pattern with the following states:
- **SplashState**: Initial loading screen
- **MainMenuState**: Main menu interface
- **GameState**: Active gameplay state

## 📁 Project Structure

```
SigmaRPG/
├── include/                 # Header files
│   ├── Animation.h         # Sprite animation system
│   ├── AssetsManager.h     # Asset loading and management
│   ├── DEFINITIONS.h       # Game constants and paths
│   ├── Game.h             # Main game class
│   ├── GameState.h        # Gameplay state
│   ├── InputManager.h     # Input handling
│   ├── Logger.h           # Logging system
│   ├── MainMenuState.h    # Main menu state
│   ├── Movement.h         # Player movement system
│   ├── Player.h           # Player character
│   ├── SplashState.h      # Splash screen state
│   ├── State.h            # Base state class
│   └── StateMachine.h     # State management
├── src/                    # Source files
│   ├── Animation.cpp
│   ├── AssetsManager.cpp
│   ├── Game.cpp
│   ├── GameState.cpp
│   ├── InputManager.cpp
│   ├── Logger.cpp
│   ├── main.cpp           # Entry point
│   ├── MainMenuState.cpp
│   ├── Movement.cpp
│   ├── Player.cpp
│   ├── SplashState.cpp
│   └── StateMachine.cpp
├── resources/              # Game assets
│   ├── background_splash.png
│   ├── BODY_male.png
│   └── player.png
├── CMakeLists.txt         # CMake configuration
└── README.md              # This file
```

## 🚀 Building the Project

### Prerequisites

- **CMake** (version 3.30 or higher)
- **C++20** compatible compiler (GCC, Clang, or MSVC)
- **SFML 3.0** (Graphics component)

### Build Instructions

1. **Clone the repository**:
   ```bash
   git clone <repository-url>
   cd SigmaRPG
   ```

2. **Create build directory**:
   ```bash
   mkdir build
   cd build
   ```

3. **Configure with CMake**:
   ```bash
   cmake ..
   ```

4. **Build the project**:
   ```bash
   cmake --build .
   ```

### Running the Game

After building, run the executable:
```bash
./src/SigmaRPG
```

## 🎯 Game Controls

- **WASD**: Move player character

## 🔧 Development

### Adding New States

1. Create a new state class inheriting from `State`
2. Implement required virtual methods:
   - `init()`: Initialize state resources
   - `handleInput()`: Handle user input
   - `update(float dt)`: Update game logic
   - `render(float dt)`: Render graphics

3. Add state to the state machine in the appropriate location

### Adding New Assets

1. Place assets in the `resources/` directory
2. Add path definitions in `DEFINITIONS.h`
3. Load assets in the appropriate state's `init()` method

### Movement System

The movement system uses a grid-based approach with smooth interpolation:
- **Grid Position**: Integer coordinates for game logic
- **Target Position**: Floating-point coordinates for smooth movement
- **Movement Speed**: Configurable in the `Movement` class

### Animation System

The animation system supports:
- **Sprite Sheets**: Multi-frame animations
- **Directional Animation**: Different animation rows for each direction
- **Configurable Speed**: Adjustable animation timing
- **Frame-based**: Supports variable frame counts

## 📝 Logging

The game includes a comprehensive logging system:
- Log file: `log.txt` (relative to executable)
- Log levels: Debug, Info, Warning, Error, Critical
- Automatic timestamping
- File and console output

## 🛠️ Technical Details

- **Resolution**: 1920x1080 (configurable)
- **Frame Rate**: 60 FPS (fixed timestep)
- **Tile Size**: 64x64 pixels
- **Movement Speed**: 100 pixels/second
- **Animation Speed**: 0.1 seconds per frame

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Ensure the project builds successfully
5. Submit a pull request

## 📄 License

- GNU GPLv3

## 🐛 Known Issues

- Project is under development

## 🔮 Future Enhancements

- Adding maps, quests, etc.
