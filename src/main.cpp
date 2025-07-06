#include <iostream>
#include <Game.h>
int main() {
    Game game(800, 600, "SIGMA");
    game.run();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}