#ifndef GAME_V1_H_INCLUDED
#define GAME_V1_H_INCLUDED

#include <SFML/Graphics.hpp>
//#include <vector>
#include <iostream>
#include "snake.h"
#include "world.h"

#include <string>

// Klasa koja predstavlja igru.
class Game{
public:
    Game();
    void run();
private:
    // Procesiraj događaje
    void processEvents();
    // konstruiraj novo stanje igre
    void update(sf::Time dt);
    // iscrtaj novo stanje
    void render();
private:
    sf::RenderWindow mWindow;
    World mWorld;
    Snake mSnake;
    sf::Time mTimePerFrame;

    void handlePlayerInput(sf::Keyboard::Key code);
};

#endif // GAME-V1_H_INCLUDED
