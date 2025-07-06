#include "Animation.h"

Animation::Animation(float animationSpeed, int totalFrames, sf::Vector2i spriteSize)
    : m_animationSpeed(animationSpeed), m_currentFrame(0), m_totalFrames(totalFrames),
      m_spriteSize(spriteSize), m_lastDirection(MoveDirection::STILL), m_isPlaying(false) {
}

void Animation::play() {
    m_isPlaying = true;
}

void Animation::pause() {
    m_isPlaying = false;
}

void Animation::stop() {
    m_isPlaying = false;
    m_currentFrame = 0;
}

void Animation::update(float dt) {
    if (!m_isPlaying) return;
    
    if (m_animationClock.getElapsedTime().asSeconds() >= m_animationSpeed) {
        m_currentFrame = (m_currentFrame + 1) % m_totalFrames;
        m_animationClock.restart();
    }
}

sf::IntRect Animation::getCurrentSpriteRect(MoveDirection direction) {
    int row = getDirectionRow(direction);
    return sf::IntRect(
        {m_currentFrame * m_spriteSize.x, row * m_spriteSize.y},
        {m_spriteSize.x, m_spriteSize.y}
    );
}

int Animation::getDirectionRow(MoveDirection direction) {
    if (direction == MoveDirection::STILL) {
        return m_lastDirection == MoveDirection::STILL ? 2 : getDirectionRow(m_lastDirection);
    }
    
    switch (direction) {
        case MoveDirection::DOWN:  return 2;
        case MoveDirection::LEFT:  return 1;
        case MoveDirection::RIGHT: return 3;
        case MoveDirection::UP:    return 0;
        default: return 2;
    }
} 