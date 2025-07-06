#include "GameState.h"

GameState::GameState(GameDataRef data) : m_data(data) {}
GameState::~GameState() {}
void GameState::init() {
    m_data->assets.loadTexture("GameState Background", GAMESTATE_BACKGROUND_PATH);

    m_background = sf::Sprite(this->m_data->assets.getTexture("GameState Background"));
}
void GameState::handleInput() {

}
void GameState::update(float dt) {

}
void GameState::render(float dt) {

}

