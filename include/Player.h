#ifndef PLAYER_H
#define PLAYER_H

#include <Game.h>
#include <SFML/Graphics.hpp>
#include <Movement.h>
#include <Animation.h>

class Player {
    GameDataRef m_data;
    std::optional<sf::Sprite> m_sprite;
    sf::Texture m_texture;
    sf::Clock m_clock;
    sf::Clock m_movementClock;

    MoveDirection m_move;
    Movement m_movement;
    Animation m_animation;
    
public:
    Player(GameDataRef data);
    ~Player();
    void move(MoveDirection whichWay);
    void update(float dt);
    void render(float dt);
    sf::Vector2i getGridPosition() const { return m_movement.getGridPosition(); }
    bool isMoving() const { return m_movement.isMoving(); }
};

#endif //PLAYER_H
