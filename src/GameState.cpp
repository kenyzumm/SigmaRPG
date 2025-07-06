#include "GameState.h"
#include "Movement.h"

GameState::GameState(GameDataRef data) : m_data(data) {

}
GameState::~GameState() {
    delete m_player;
}
void GameState::init() {
    m_data->assets.loadTexture("GameState Background", GAMESTATE_BACKGROUND_PATH);

    m_background = sf::Sprite(this->m_data->assets.getTexture("GameState Background"));

    m_data->assets.loadTexture("BODY_male", BODY_MALE_TEXTURE_PATH);

    m_player = new Player(m_data);
}
void GameState::handleInput() {
    while (const std::optional<sf::Event> event = this->m_data->window->pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            this->m_data->window->close();
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        this->m_player->move(MoveDirection::LEFT);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        this->m_player->move(MoveDirection::RIGHT);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        this->m_player->move(MoveDirection::UP);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        this->m_player->move(MoveDirection::DOWN);
    }
}
void GameState::update(float dt) {
    m_player->update(dt);
}
void GameState::render(float dt) {
    m_data->window->clear();
    m_data->window->draw(*m_background);
    m_player->render(dt);
    m_data->window->display();
}

