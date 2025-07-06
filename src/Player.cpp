#include "Player.h"
#include <iostream>

Player::Player(GameDataRef data) : m_data(data), m_animation(0.1f, 9, {64, 64}) {
    // Load texture
    m_texture = m_data->assets.getTexture("BODY_male");
    m_sprite = sf::Sprite(m_texture);
    m_sprite->setTextureRect(sf::IntRect({0, 0}, {64, 64}));

    //m_sprite->setScale({0.5f, 0.5f});
    
    // Set initial sprite position
    m_sprite->setPosition(m_movement.getCurrentPosition());
}

Player::~Player() {}

void Player::move(MoveDirection whichWay) {
    if (!m_movement.isMoving()) {
        m_move = whichWay;
    }
}

void Player::update(float dt) {
    // Handle new movement input
    if (!m_movement.isMoving() && m_move != MoveDirection::STILL) {
        // Store the direction before moving
        MoveDirection currentDirection = m_move;
        
        m_movement.move(m_move);
        m_move = MoveDirection::STILL;
        
        // Set the animation direction
        m_animation.setLastDirection(currentDirection);
    }
    
    // Update movement
    m_movement.update(dt);
    
    // Update animation
    if (m_movement.isMoving()) {
        m_animation.play();
    } else {
        m_animation.stop();
    }
    
    m_animation.update(dt);
    
    // Update sprite rectangle
    m_sprite->setTextureRect(m_animation.getCurrentSpriteRect(m_animation.getLastDirection()));
    
    // Update sprite position
    m_sprite->setPosition(m_movement.getCurrentPosition());
}

void Player::render(float dt) {
    m_data->window->draw(*m_sprite);
}

