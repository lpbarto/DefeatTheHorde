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


GameState::GameState(Game* game): m_game(game){
}


void GameState::pressOne(int number) {

}

WellcomeState::WellcomeState(Game* game): GameState(game){

    m_sprite.setTexture(game->getLogo());
    m_sprite.setPosition(165,200);

    m_text.setFont(game->getFont());
    m_text.setString("Press Start");
    m_text.setCharacterSize(50);

    centerOrigin(m_text);
    m_text.setPosition(600,500);

    m_displayText = true;

}

LevelInfoState::LevelInfoState(Game* game): GameState(game){

    m_text.setFont(game->getFont());
    m_text.setString("Level 1");
    m_text.setCharacterSize(50);

    centerOrigin(m_text);
    m_text.setPosition(600,300);


}



CharacterSelectionState::CharacterSelectionState(Game* game)
        : GameState(game)

{
    if(!m_heroTexture.loadFromFile("assets/heroTexture.png"))
        throw std::runtime_error("unable to load heroTexture file");

    m_text.setFont(game->getFont());
    m_text.setString("Chose a character pressing a number");
    m_text.setCharacterSize(40);

    centerOrigin(m_text);
    m_text.setPosition(500,100);

    m_sprite.setTexture(m_heroTexture);
    m_sprite.setPosition(0,240);

}

GetReadyState::GetReadyState(Game* game): GameState(game){

    m_text.setFont(game->getFont());
    m_text.setString("Press Start when you are ready");
    m_text.setCharacterSize(40);

    centerOrigin(m_text);
    m_text.setPosition(500,300);

}

int GameState::m_cN = 0;

PlayingState::PlayingState(Game* game)
        : GameState(game)
//,m_hero(game->getTexture())
,m_map(game->getTexture())
,m_hero(nullptr)

{

    m_map.loadLevel("large-level-villain");
    //m_hero.move(400,50);


    m_hero = new Hero(game->getTexture(), m_cN);
    m_hero->setMap(&m_map);
    m_hero->setPosition(m_map.mapCellToPixel(m_map.getHeroPosition()));

  for (auto villainPosition : m_map.getVillainPositions())
    {
        Villain* villain = new Villain(game->getTexture());
        villain->setMap(&m_map);
        villain->setPosition(m_map.mapCellToPixel(villainPosition));

        m_villains.push_back(villain);
    }


    m_camera.setSize(sf::Vector2f(1280,960));

   // m_camera.setCenter(m_hero->getPosition());


}

PlayingState::~PlayingState() {

    delete m_hero;

    for (Villain* villain : m_villains)
        delete villain;

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


}

void CharacterSelectionState::pressOne(int number){

    m_cN = number;

    getGame()->changeGameState(GameState::Playing);




}

void CharacterSelectionState::moveStick(sf::Vector2i direction) {



}
void CharacterSelectionState::update(sf::Time delta) {




}
void CharacterSelectionState::draw(sf::RenderWindow &window) {

    window.draw(m_sprite);
    window.draw(m_text);

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

    m_hero->setDirection(direction);

}
void PlayingState::update(sf::Time delta) {

    m_camera.setCenter(m_hero->getPosition());

    if(m_camera.getCenter().x < 640)
        m_camera.setCenter(640,m_camera.getCenter().y);
    if(m_camera.getCenter().y < 480)
        m_camera.setCenter(m_camera.getCenter().x, 480);

    if(m_camera.getCenter().x > m_map.getSize().x * 64 - 640)
        m_camera.setCenter(m_map.getSize().x * 64 - 640, m_camera.getCenter().y);
    if(m_camera.getCenter().y > m_map.getSize().y * 64 - 480)
        m_camera.setCenter(m_camera.getCenter().x, m_map.getSize().y * 64 - 480);


    m_hero->update(delta);

   for (Villain* villain : m_villains)
      villain->update(delta);


}
void PlayingState::draw(sf::RenderWindow &window) {

    window.setView(m_camera);
    window.draw(m_map);
    window.draw(*m_hero);

    for (Villain* villain : m_villains)
        window.draw(*villain);


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




