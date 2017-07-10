//
// Created by Lapo Bartolacci on 25/06/17.
//

#include "Game.h"
#include <iostream>

Game::Game()
        :m_window(sf::VideoMode(1280, 720), "VideoGame")
{
    if(!m_font.loadFromFile("assets/3Dventure.ttf"))
        throw std::runtime_error("unable to load font file");

    if(!m_logo.loadFromFile("assets/logo.png"))
        throw std::runtime_error("unable to load the logo file");

    if(!m_texture.loadFromFile("assets/hero-animation.png"))
        throw std::runtime_error("unable to load texture file");

    m_gameStates[GameState::Wellcome] = new WellcomeState(this);
    m_gameStates[GameState::LevelInfo] = new LevelInfoState(this);
    m_gameStates[GameState::CharacterSelection] = new CharacterSelectionState(this);
    m_gameStates[GameState::GetReady] = new GetReadyState(this);
    m_gameStates[GameState::Playing] = new PlayingState(this);
    m_gameStates[GameState::Won] = new WonState(this);
    m_gameStates[GameState::Lost] = new LostState(this);

    changeGameState(GameState::Wellcome);

}

Game::~Game(){
    for(GameState* gameState : m_gameStates)
         delete gameState;
}

void Game::run() {

    sf::Clock frameClock;
    while (m_window.isOpen()){

        sf::Event event;
        while(m_window.pollEvent(event)){

            if(event.type == sf::Event::Closed) {
                m_window.close();
            }

            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::I)
                    m_currentState->pressStart();

                if(event.key.code == sf::Keyboard::Left)
                    m_currentState->moveStick(sf::Vector2i(-1,0));
                if(event.key.code == sf::Keyboard::Right)
                    m_currentState->moveStick(sf::Vector2i(1,0));

            }


        }

        m_currentState->update(frameClock.restart());
        m_window.clear();
        m_currentState->draw(m_window);
        m_window.display();
    }
}

void Game::changeGameState(GameState::State gameState) {

    m_currentState = m_gameStates[gameState];

}

sf::Font& Game::getFont() {
    return m_font;
}

sf::Texture& Game::getLogo() {
    return m_logo;
}

sf::Texture& Game::getTexture() {
    return m_texture;
}
