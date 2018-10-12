#include "game.h"
#include <typeinfo>

// Implementacija Game klase

Game::Game() : mWindow( sf::VideoMode(800,600), "Snake by Nesto"), score(0)
{
   // Ovdje alocirati sva stanja i postaviti pokazivač na trenutno stanje.   
    mTimePerFrame = sf::seconds( 0.13f );



    //cout << mpGameStates.size() << ", "<< mpGameStates.max_size()<<endl;
    mpGameStates[0] = new WelcomeState( this , mWindow.getSize());
    mpGameStates[1] = new PlayingState( this, mWindow.getSize());
    mpGameStates[2] = new WonState( this, mWindow.getSize());
    mpGameStates[3] = new LostState( this, mWindow.getSize());
    mpGameStates[4] = new ExitingState( this, mWindow.getSize());


    changeState(GameState::State::Welcome);

}

// Primjer run - metode. Zavisni dijelovi koda se delegiraju GameState klasama
// kroz pokazivač mpCurrentGameState.
void Game::run(){
    sf::Clock clock;     
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while(mWindow.isOpen())
    {
       processEvents();
       timeSinceLastUpdate += clock.restart();
       while(timeSinceLastUpdate > mTimePerFrame)
       {
          timeSinceLastUpdate -= mTimePerFrame;
          processEvents();
          mpCurrentGameState->update(mTimePerFrame);
       }
       // rendering
       mWindow.clear();
       mpCurrentGameState->render(mWindow);
       mWindow.display();
    }
}

// obrada događaja
void Game::processEvents(){
   // implementacija  
    sf::Event event;
    while( mWindow.pollEvent(event) )
    {
        switch( event.type ){
            case sf::Event::Closed:
                mWindow.close();
                break;
            case sf::Event::KeyPressed:
                mpCurrentGameState->handlePlayerInput(event.key.code);
                break;
        }
    }
}

int Game::set_or_getScore( int x ){
    if( x == -1 )   // pozvan getscore
        return score;
    else
        score = x;
    return -100;
}

void Game::faster(){
    mTimePerFrame -=  sf::seconds(0.009f);
}

/*
sf::Vector2u Game::windowSize(){
   return mWindow.getSize();
}*/
