//
// Created by Lapo Bartolacci on 25/06/17.
//

#include "GameState.h"
#include "Game.h"
#include <iostream>

template <typename T>
void centerOrigin(T& drawable){
    sf::FloatRect bound = drawable.getLocalBounds();
    drawable.setOrigin(bound.width/2, bound.height/2);
}

GameState::GameState(Game* game): m_game(game){}

WellcomeState::WellcomeState(Game* game): GameState(game){

    m_sprite.setTexture(game->getLogo());
    m_sprite.setPosition(20,50);

    m_text.setFont(game->getFont());
    m_text.setString("Press Start");

    centerOrigin(m_text);
    m_text.setPosition(240,140);

    m_displayText = true;

}

LevelInfoState::LevelInfoState(Game* game): GameState(game){

    m_text.setFont(game->getFont());
    m_text.setString("Level 1");
    m_text.setCharacterSize(28);

    centerOrigin(m_text);
    m_text.setPosition(240,240);


}

CharacterSelectionState::CharacterSelectionState(Game* game)
        : GameState(game)

{

}

GetReadyState::GetReadyState(Game* game): GameState(game){

    m_text.setFont(game->getFont());
    m_text.setString("Press Start when you are ready");
    m_text.setCharacterSize(14);

    centerOrigin(m_text);
    m_text.setPosition(240,240);

}

PlayingState::PlayingState(Game* game)
        : GameState(game)
//,m_hero(game->getTexture())
,m_hero(nullptr)

{

    m_map.loadLevel("level");
    //m_hero.move(400,50);

    m_hero = new Hero(game->getTexture());
    m_hero->setMap(&m_map);
    m_hero->setPosition(m_map.mapCellToPixel(m_map.getHeroPosition()));


}

PlayingState::~PlayingState() {
    delete m_hero;
}

WonState::WonState(Game* game): GameState(game){


    m_text.setFont(game->getFont());
    m_text.setString("You Won!!  press start to the next level");
    m_text.setCharacterSize(14);

    centerOrigin(m_text);
    m_text.setPosition(240,240);

}

LostState::LostState(Game* game): GameState(game){


    m_text.setFont(game->getFont());
    m_text.setString("You Lost :(  press start to try again");
    m_text.setCharacterSize(14);

    centerOrigin(m_text);
    m_text.setPosition(240,240);

}



Game* GameState::getGame() const{
    return m_game;
}


void WellcomeState::pressStart() {

    getGame()->changeGameState(GameState::LevelInfo);

}
void WellcomeState::moveStick(sf::Vector2i direction) {

}
void WellcomeState::update(sf::Time delta) {

    static sf::Time timeBuffer = sf::Time::Zero;
    timeBuffer += delta;

    while(timeBuffer >= sf::seconds(0.5)){
        m_displayText = !m_displayText;
        timeBuffer -= sf::seconds(1);
    }

}
void WellcomeState::draw(sf::RenderWindow &window) {

    window.draw(m_sprite);

    if(m_displayText)
    window.draw(m_text);


}



void LevelInfoState::pressStart() {

    getGame()->changeGameState(GameState::CharacterSelection);

}
void LevelInfoState::moveStick(sf::Vector2i direction) {

}
void LevelInfoState::update(sf::Time delta) {

}
void LevelInfoState::draw(sf::RenderWindow &window) {

    window.draw(m_text);

}



void CharacterSelectionState::pressStart() {

    getGame()->changeGameState(GameState::GetReady);

}
void CharacterSelectionState::moveStick(sf::Vector2i direction) {



}
void CharacterSelectionState::update(sf::Time delta) {


}
void CharacterSelectionState::draw(sf::RenderWindow &window) {



}



void GetReadyState::pressStart() {

    getGame()->changeGameState(GameState::Playing);

}
void GetReadyState::moveStick(sf::Vector2i direction) {

}
void GetReadyState::update(sf::Time delta) {

}
void GetReadyState::draw(sf::RenderWindow &window) {

    window.draw(m_text);

}



void PlayingState::pressStart() {

}
void PlayingState::moveStick(sf::Vector2i direction) {

}
void PlayingState::update(sf::Time delta) {
    m_hero->update(delta);

}
void PlayingState::draw(sf::RenderWindow &window) {

    window.draw(m_map);
    window.draw(*m_hero);

}



void WonState::pressStart() {

}
void WonState::moveStick(sf::Vector2i direction) {

}
void WonState::update(sf::Time delta) {

}
void WonState::draw(sf::RenderWindow &window) {

    window.draw(m_text);

}



void LostState::pressStart() {

    getGame()->changeGameState(GameState::Wellcome);

}
void LostState::moveStick(sf::Vector2i direction) {

}
void LostState::update(sf::Time delta) {

}
void LostState::draw(sf::RenderWindow &window) {

    window.draw(m_text);

}
