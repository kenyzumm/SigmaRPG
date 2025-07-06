#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <SFML/Graphics.hpp>

enum class MoveDirection { STILL = 0, LEFT, RIGHT, DOWN, UP };

class Movement {
    const float m_tileSize;
    const float m_speed;

    sf::Vector2i m_gridPosition;
    sf::Vector2f m_targetPosition;
    sf::Vector2f m_currentPosition;

    bool m_isMoving;
    
public:
    Movement(float tileSize = 64.0f, float speed = 100.0f);
    ~Movement() = default;
    
    // Movement control
    void move(MoveDirection direction);
    void update(float dt);
    
    // Getters
    sf::Vector2f getCurrentPosition() const { return m_currentPosition; }
    sf::Vector2i getGridPosition() const { return m_gridPosition; }
    bool isMoving() const { return m_isMoving; }
    
    // Setters
    void setPosition(sf::Vector2i gridPos);
    
    // Utility
    sf::Vector2f getTargetPosition() const { return m_targetPosition; }
    float getDistanceToTarget() const;
};

#endif // MOVEMENT_H 