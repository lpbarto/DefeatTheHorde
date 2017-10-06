//
// Created by Lapo Bartolacci on 25/06/17.
//

#ifndef VIDEOGAME_GAME_H
#define VIDEOGAME_GAME_H

#include "GameState.h"
#include <SFML/Graphics.hpp>
#include <array>

class Game {

public:

    Game();
    ~Game();

    void run();

    sf::Font& getFont();
    sf::Texture& getLogo();
    sf::Texture& getTexture();
    sf::Texture& getTextureBadge();



    void changeGameState(GameState::State gameState);


private:

    sf::RenderWindow m_window;
    GameState* m_currentState;
    std::array<GameState*, GameState::Lost> m_gameStates;

    sf::Font m_font;
    sf::Texture m_logo;
    sf::Texture m_texture;
    sf::Texture m_textureBadge;




};


#endif //VIDEOGAME_GAME_H
