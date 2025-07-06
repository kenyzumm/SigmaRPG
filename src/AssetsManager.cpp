#include "AssetsManager.h"

AssetsManager::AssetsManager() {}
AssetsManager::~AssetsManager() {}
void AssetsManager::loadTexture(std::string name, std::string filename) {
    sf::Texture texture;
    if (texture.loadFromFile(filename)) {
        this->m_textures[name] = texture;
    }
}
void AssetsManager::loadFont(std::string name, std::string filename) {
    sf::Font font;
    if (font.openFromFile(filename)) {
        this->m_fonts[name] = font;
    }
}



sf::Texture &AssetsManager::getTexture(std::string name) {}
sf::Font &AssetsManager::getFont(std::string name) {}
