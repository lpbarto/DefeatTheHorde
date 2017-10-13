//
// Created by Lapo Bartolacci on 25/06/17.
//

#ifndef VIDEOGAME_GAMESTATE_H
#define VIDEOGAME_GAMESTATE_H

#include <SFML/Graphics.hpp>
#include "Hero.h"
#include "Villain.h"
#include "Map.h"
#include "VillainFactory.h"

class Game;

class GameState {
public:
    enum State{
        Wellcome,
        CharacterSelection,
        Playing,
        Lost
    };

    GameState (Game* game);

    Game* getGame() const;


    virtual void pressA();
    virtual void pressStart()=0;
    virtual void pressOne(int number);
    virtual void moveStick(sf::Vector2i direction)=0;
    virtual void update(sf::Time delta)=0;
    virtual void draw(sf::RenderWindow& window)=0;

    static int m_cN;

private:
    Game* m_game;


};

class WellcomeState : public GameState {

public:
    WellcomeState (Game* game);
    virtual void pressStart();
    virtual void moveStick(sf::Vector2i direction);
    virtual void update(sf::Time delta);
    virtual void draw(sf::RenderWindow& window);

private:
    sf::Text m_text;
    sf::Sprite m_sprite;

    bool m_displayText;
};


class CharacterSelectionState : public GameState {

public:
    CharacterSelectionState (Game* game);
    virtual void pressStart();
    void pressOne(int number);
    virtual void moveStick(sf::Vector2i direction);
    virtual void update(sf::Time delta);
    virtual void draw(sf::RenderWindow& window);


private:
    sf::Text m_text;
    sf::Sprite m_sprite;
    sf::Texture m_heroTexture;


};

class PlayingState : public GameState {

public:
    PlayingState (Game* game);
    ~PlayingState();
    virtual void pressA();
    virtual void pressStart();
    virtual void moveStick(sf::Vector2i direction);
    virtual void update(sf::Time delta);
    virtual void draw(sf::RenderWindow& window);

    void loadNextLevel();
    void moveCharacterToInitialPosition();
    void updateCameraPosition();
    void resetToZero();
    void resetCurrentLevel();

    int getKills();

private:

    int m_level;

    Achievements* achievements;

    Map m_map;
    Hero* m_hero;
    std::vector<Villain*> m_villains;

    sf::View m_camera;
    sf::RenderTexture m_scene;

    sf::Text m_HeroHpText;
    sf::Text m_levelText;
    sf::Text m_remainingVillainsText;
    sf::Sprite m_runnerBadge;
    sf::Sprite m_killerBadge;

};


class LostState : public GameState {

public:
    LostState (Game* game, GameState* playingState);
    virtual void pressStart();
    virtual void moveStick(sf::Vector2i direction);
    virtual void update(sf::Time delta);
    virtual void draw(sf::RenderWindow& window);

private:

    sf::Text m_text;
    sf::Text m_textKills;
    PlayingState* m_playingState;


};

#endif //VIDEOGAME_GAMESTATE_H
