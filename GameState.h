//
// Created by Lapo Bartolacci on 25/06/17.
//

#ifndef VIDEOGAME_GAMESTATE_H
#define VIDEOGAME_GAMESTATE_H

#include <SFML/Graphics.hpp>
#include "Hero.h"
#include "Villain.h"
#include "Map.h"

class Game;

class GameState {
public:
    enum State{
        Wellcome,
        LevelInfo,
        CharacterSelection,
        GetReady,
        Playing,
        Won,
        Lost
    };

    GameState (Game* game);
    Game* getGame() const;

    virtual void pressStart()=0;
    virtual void pressOne(int number);
    virtual void moveStick(sf::Vector2i direction)=0;
    virtual void update(sf::Time delta)=0;
    virtual void draw(sf::RenderWindow& window)=0;

    int m_cN;

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

class LevelInfoState : public GameState {

public:
    LevelInfoState (Game* game);
    virtual void pressStart();
    virtual void moveStick(sf::Vector2i direction);
    virtual void update(sf::Time delta);
    virtual void draw(sf::RenderWindow& window);

private:

    sf::Text m_text;

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

class GetReadyState : public GameState {

public:
    GetReadyState (Game* game);
    virtual void pressStart();
    virtual void moveStick(sf::Vector2i direction);
    virtual void update(sf::Time delta);
    virtual void draw(sf::RenderWindow& window);

private:

    sf::Text m_text;

};

class PlayingState : public GameState {

public:
    PlayingState (Game* game);
    ~PlayingState();
    virtual void pressStart();
    virtual void moveStick(sf::Vector2i direction);
    virtual void update(sf::Time delta);
    virtual void draw(sf::RenderWindow& window);

private:

    Map m_map;
    Hero* m_hero;

    sf::View m_camera;

};

class WonState : public GameState {

public:
    WonState (Game* game);
    virtual void pressStart();
    virtual void moveStick(sf::Vector2i direction);
    virtual void update(sf::Time delta);
    virtual void draw(sf::RenderWindow& window);

private:

    sf::Text m_text;

};

class LostState : public GameState {

public:
    LostState (Game* game);
    virtual void pressStart();
    virtual void moveStick(sf::Vector2i direction);
    virtual void update(sf::Time delta);
    virtual void draw(sf::RenderWindow& window);

private:

    sf::Text m_text;

};

#endif //VIDEOGAME_GAMESTATE_H
