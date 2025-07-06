#include "Movement.h"

Movement::Movement(float tileSize, float speed) 
    : m_tileSize(tileSize), m_speed(speed), m_isMoving(false) {
    // Initialize positions
    m_gridPosition = {0, 0};
    m_currentPosition = {0.0f, 0.0f};
    m_targetPosition = m_currentPosition;
}

void Movement::move(MoveDirection direction) {
    if (m_isMoving || direction == MoveDirection::STILL) return;
    
    sf::Vector2i newGridPosition = m_gridPosition;
    
    switch (direction) {
        case MoveDirection::UP:    newGridPosition.y -= 1; break;
        case MoveDirection::DOWN:  newGridPosition.y += 1; break;
        case MoveDirection::LEFT:  newGridPosition.x -= 1; break;
        case MoveDirection::RIGHT: newGridPosition.x += 1; break;
        default: return;
    }
    
    m_gridPosition = newGridPosition;
    m_targetPosition = sf::Vector2f(newGridPosition.x * m_tileSize, newGridPosition.y * m_tileSize);
    m_isMoving = true;
}

void Movement::update(float dt) {
    if (!m_isMoving) return;
    
    sf::Vector2f direction = m_targetPosition - m_currentPosition;
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    
    if (distance > 0.5f) {
        // Normalize and move
        direction = direction / distance;
        sf::Vector2f movement = direction * m_speed * dt;
        
        // Prevent overshooting
        if (std::abs(movement.x) > std::abs(direction.x)) movement.x = direction.x;
        if (std::abs(movement.y) > std::abs(direction.y)) movement.y = direction.y;
        
        m_currentPosition += movement;
    } else {
        // Snap to target
        m_currentPosition = m_targetPosition;
        m_isMoving = false;
    }
}

void Movement::setPosition(sf::Vector2i gridPos) {
    m_gridPosition = gridPos;
    m_currentPosition = sf::Vector2f(gridPos.x * m_tileSize, gridPos.y * m_tileSize);
    m_targetPosition = m_currentPosition;
    m_isMoving = false;
}

float Movement::getDistanceToTarget() const {
    sf::Vector2f direction = m_targetPosition - m_currentPosition;
    return std::sqrt(direction.x * direction.x + direction.y * direction.y);
}
