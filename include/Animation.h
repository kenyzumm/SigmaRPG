#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <Movement.h>

class Animation {
private:
    sf::Clock m_animationClock;
    float m_animationSpeed;
    int m_currentFrame;
    int m_totalFrames;
    sf::Vector2i m_spriteSize;
    MoveDirection m_lastDirection;
    bool m_isPlaying;
    
    int getDirectionRow(MoveDirection direction);
    
public:
    Animation(float animationSpeed = 0.1f, int totalFrames = 9, sf::Vector2i spriteSize = {64, 64});
    ~Animation() = default;
    
    // Control
    void play();
    void pause();
    void stop();
    void update(float dt);
    
    // Getters
    bool isPlaying() const { return m_isPlaying; }
    int getCurrentFrame() const { return m_currentFrame; }
    MoveDirection getLastDirection() const { return m_lastDirection; }
    sf::IntRect getCurrentSpriteRect(MoveDirection direction);
    
    // Setters
    void setAnimationSpeed(float speed) { m_animationSpeed = speed; }
    void setTotalFrames(int frames) { m_totalFrames = frames; }
    void setSpriteSize(sf::Vector2i size) { m_spriteSize = size; }
    void setLastDirection(MoveDirection direction) { m_lastDirection = direction; }
};

#endif // ANIMATION_H 