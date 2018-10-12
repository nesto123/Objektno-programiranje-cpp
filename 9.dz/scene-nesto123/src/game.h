#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "sceneGraph.h"

class Game{
public:
    Game();
    void run();
private:
    // Procesiraj događaje
    void processEvents();
    // konstruiraj novo stanje igre
    void update(sf::Time const &b);
    // iscrtaj novo stanje
    void render();
private:
    // implementacijski detalji

    sf::RenderWindow mWindow;
    SceneNode mScene;
    sf::Time mTimePerFrame;

    sf::Vector2f previous_position, pomak;
    bool mouse_pressed;
    sf::RenderStates state;

    void offset( sf::Vector2f vec );
    void handleInput( sf::Keyboard::Key code );
};


#endif
