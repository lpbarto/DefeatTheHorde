//
// Created by Lapo Bartolacci on 25/06/17.
//

#include "GameState.h"
#include "Game.h"
#include <iostream>
#include <cmath>





template <typename T>
void centerOrigin(T& drawable){
    sf::FloatRect bound = drawable.getLocalBounds();
    drawable.setOrigin(bound.width/2, bound.height/2);
}


GameState::GameState(Game* game): m_game(game){
}


void GameState::pressOne(int number) {

}
void GameState::pressA() {

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
,m_level(0)


{
    //m_hero.move(400,50);


    m_hero = new Hero(game->getTexture(), m_cN);
    m_hero->setMap(&m_map);
    m_hero->setPosition(m_map.mapCellToPixel(m_map.getHeroPosition()));

    Achievements *achievements = new Achievements;
    m_hero->addObserver(achievements);


    resetToZero();

    m_camera.setSize(sf::Vector2f(1280,960));
    m_scene.create(1280,960);

    m_HeroHpText.setFont(game->getFont());
    m_HeroHpText.setCharacterSize(40);
    m_HeroHpText.setPosition(10, 960);

    m_levelText.setFont(game->getFont());
    m_levelText.setCharacterSize(40);
    m_levelText.setPosition(160, 960);

    m_remainingVillainsText.setFont(game->getFont());
    m_remainingVillainsText.setCharacterSize(40);
    m_remainingVillainsText.setPosition(350, 960);


    m_runnerBadge.setTexture(getGame()->getTextureBadge());
    m_runnerBadge.setTextureRect(sf::IntRect(10,7,111,42));
    m_runnerBadge.setPosition(sf::Vector2f(700, 960));

    m_killerBadge.setTexture(getGame()->getTextureBadge());
    m_killerBadge.setTextureRect(sf::IntRect(151,5,129,34));
    m_killerBadge.setPosition(sf::Vector2f(900, 961));


   // m_camera.setCenter(m_hero->getPosition());
}

PlayingState::~PlayingState() {

    delete m_hero;

    for (Villain* villain : m_villains)
        delete villain;

}

WonState::WonState(Game* game, GameState* playingState):
        GameState(game)
,m_playingState(static_cast<PlayingState*>(playingState))
{


    m_text.setFont(game->getFont());
    m_text.setString("You Won !");
    m_text.setCharacterSize(50);

    centerOrigin(m_text);
    m_text.setPosition(600,300);

}

LostState::LostState(Game* game): GameState(game){


    m_text.setFont(game->getFont());
    m_text.setString("You Lost :( ");
    m_text.setCharacterSize(50);

    centerOrigin(m_text);
    m_text.setPosition(600,300);

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

    getGame()->changeGameState(GameState::Won);


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

void PlayingState::resetToZero()
{
    m_level = 0;
    resetCurrentLevel();

}

void PlayingState::resetCurrentLevel()
{
    m_level--;
    loadNextLevel();
}

void PlayingState::loadNextLevel() {

    m_map.loadLevel("large-level-villain");

    m_level++;



    int mapLevel = m_level % 3;

    m_levelText.setString("level " + std::to_string(mapLevel));

    if(mapLevel == 0) {
        m_map.loadLevel("large-level-villain");
    }else if(mapLevel == 1){
        m_map.loadLevel("large-level-villain-3");
    } else if(mapLevel == 2){
        m_map.loadLevel("large-level-villain-6");
    }

    for(Villain* villain : m_villains)
        delete villain;

    m_villains.clear();

    VillainFactory* factory = new VillainFactory;

    for (auto villainPosition : m_map.getVillainPositions())
    {
       int randVillain = rand() % 6;


        if(randVillain % 2 == 0) {
            Villain* villain = factory->createVillain(getGame()->getTexture(), m_hero, "zombie");

            villain->setMap(&m_map);
            villain->setPosition(m_map.mapCellToPixel(villainPosition));

            m_villains.push_back(villain);
        }else if(randVillain % 2 != 0) {
           Villain* villain = factory->createVillain(getGame()->getTexture(), m_hero, "robot");

            villain->setMap(&m_map);
            villain->setPosition(m_map.mapCellToPixel(villainPosition));

            m_villains.push_back(villain);
        }

    }

    for(Villain* villain : m_villains){

        int randBehavior = rand() % 2;
        NormalBehavior *normalBehavior = new NormalBehavior;
        DefensiveBehavior *defensiveBehavior = new DefensiveBehavior;
        AggressiveBehavior *aggressiveBehavior = new AggressiveBehavior;

        if(randBehavior == 0){

            villain->setBehavior(normalBehavior);
        }else if(randBehavior == 1){

            villain->setBehavior(defensiveBehavior);
        } else if(randBehavior == 2){

            villain->setBehavior(aggressiveBehavior);
        }

    }

    m_remainingVillainsText.setString("Villains: " + std::to_string(m_villains.size()));

    moveCharacterToInitialPosition();


}

void PlayingState::moveCharacterToInitialPosition()
{
    m_hero->setPosition(m_map.mapCellToPixel(m_map.getHeroPosition()));

    auto ghostPositions = m_map.getVillainPositions();
    for (unsigned int i = 0; i < m_villains.size(); i++)
        m_villains[i]->setPosition(m_map.mapCellToPixel(ghostPositions[i]));

   updateCameraPosition();
}

void PlayingState::updateCameraPosition() {

    m_camera.setCenter(m_hero->getPosition());

    if(m_camera.getCenter().x < 640)
        m_camera.setCenter(640,m_camera.getCenter().y);
    if(m_camera.getCenter().y < 480)
        m_camera.setCenter(m_camera.getCenter().x, 480);

    if(m_camera.getCenter().x > m_map.getSize().x * 64 - 640)
        m_camera.setCenter(m_map.getSize().x * 64 - 640, m_camera.getCenter().y);
    if(m_camera.getCenter().y > m_map.getSize().y * 64 - 480)
        m_camera.setCenter(m_camera.getCenter().x, m_map.getSize().y * 64 - 480);

}

void PlayingState::pressA() {

    for(Villain *villain : m_villains) {
        if (villain->getCollisionBox().intersects(m_hero->getCollisionBox())) {

            int villainHP = villain->getM_hp();

            villain->setM_hp(villainHP -= m_hero->attack());


            if(villain->getM_hp() <= 0){
                // villain->die();

                m_villains.erase(std::find(m_villains.begin(), m_villains.end(), villain));
                m_remainingVillainsText.setString("Villains: " + std::to_string(m_villains.size()));
                m_hero->notify(Killer);

            }

        }
    }


}

void PlayingState::pressStart() {



}


void PlayingState::moveStick(sf::Vector2i direction) {

    m_hero->setDirection(direction);

}
void PlayingState::update(sf::Time delta) {

    m_hero->update(delta);

   for (Villain* villain : m_villains) {
       villain->update(delta);
   }
/*    sf::Vector2f pixelPosition = m_hero->getPosition();
    sf::Vector2f offset(std::fmod(pixelPosition.x, 32), std::fmod(pixelPosition.y, 32));
    offset -= sf::Vector2f(16, 16);

    if(offset.x <= 2 && offset.x >= -2 && offset.y <= 2 && offset.y >= -2){

        sf::Vector2i cellPosition = m_map.mapPixelToCell(pixelPosition);

    }
*/

    if(m_villains.empty()){
      //  getGame()->changeGameState(GameState::Won);
       this->loadNextLevel();
    }

    if(m_hero->isDead())
        getGame()->changeGameState(GameState::Lost);

    m_HeroHpText.setString("HP:" + std::to_string(m_hero->getM_hp()));

    updateCameraPosition();


}
void PlayingState::draw(sf::RenderWindow &window) {

    m_scene.setView(m_camera);
    m_scene.draw(m_map);
    m_scene.draw(*m_hero);

    for (Villain* villain : m_villains)
        m_scene.draw(*villain);

    m_scene.display();

    window.draw(sf::Sprite(m_scene.getTexture()));

    window.draw(m_HeroHpText);
    window.draw(m_levelText);
    window.draw(m_remainingVillainsText);

     if(m_hero->runnerBadgeVisible)
     window.draw(m_runnerBadge);
      if(m_hero->killerBadgeVisible)
      window.draw(m_killerBadge);


}



void WonState::pressStart() {

}
void WonState::moveStick(sf::Vector2i direction) {

}
void WonState::update(sf::Time delta) {
/*
    static sf::Time timeBuffer = sf::Time::Zero;
    timeBuffer += delta;

    if (timeBuffer.asSeconds() > 5)
    {
        m_playingState->loadNextLevel();

      //  getGame()->changeGameState(GameState::Playing);
    }
*/
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




