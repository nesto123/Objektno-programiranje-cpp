#include "game.h"

// Implementacija klase Game.


Game::Game() : mWindow( sf::VideoMode(1000,800), "SFML window" ), mScene("base") ,previous_position(-1,-1), mouse_pressed(false), pomak(0,0){

    mTimePerFrame = sf::seconds( 0.007);

    ///     inicijalizacija background
    mScene.addComponent( (std::unique_ptr<SceneNode>)new BackgrNode(mWindow.getSize(),"background") );

    ///

    std::unique_ptr<SceneNode> raptorh(new PlaneNode("raptorh")), raptorj(new PlaneNode("raptorj")),
                                eagle( new PlaneNode("eagle")) , raptork( new PlaneNode("raptork") ),
                                raptorl( new PlaneNode("raptorl")) ;
    raptorj->addComponent( std::move(raptorh) );
    raptork->addComponent( std::move(raptorl) );
    eagle->addComponent( std::move(raptorj) );
    eagle->addComponent( std::move(raptork) );

    mScene.addComponent( std::move(eagle));
}

void Game::run(){
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while ( mWindow.isOpen() ){
        //processEvents();

        timeSinceLastUpdate += clock.restart();
        //sf::Time dt = clock.restart();
        while ( timeSinceLastUpdate > mTimePerFrame ) {
            timeSinceLastUpdate -= mTimePerFrame;
            processEvents();
            update( mTimePerFrame );
        }
        render();
    }
    return;
}

void Game::processEvents(){
    sf::Event event;
    while( mWindow.pollEvent(event) )
    {
        if( event.type == sf::Event::Closed )
            mWindow.close();

        else if ( event.type == sf::Event::MouseMoved && mouse_pressed )
            offset( sf::Vector2f(event.mouseMove.x, event.mouseMove.y) );

        else if( event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
             if( previous_position.x ==-1 && previous_position.y == -1)
                 previous_position = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
             mouse_pressed = true;
        }
        else if( event.type == sf::Event::MouseButtonReleased )
        {
            previous_position = sf::Vector2f(-1,-1);
            mouse_pressed = false;
            pomak = sf::Vector2f(0,0);
        }
        else if( event.type == sf::Event::KeyPressed )
            handleInput( event.key.code );
    }
}

void Game::update( sf::Time const &b ){

        if( pomak.x != 0 && pomak.y != 0 )
            state.transform.translate(pomak);
}

void Game::render(){
    sf::RenderWindow *_mWindow = &mWindow;

    mWindow.clear();
    _mWindow->draw(mScene,state);
    mWindow.display();
}

void Game::offset( sf::Vector2f vec ){
    pomak.x = vec.x - previous_position.x;
    pomak.y = vec.y - previous_position.y;

    previous_position = vec;
}

void Game::handleInput( sf::Keyboard::Key code ){
    if( code == sf::Keyboard::H )
        mScene.removeComponent("raptorh");
    else if( code == sf::Keyboard::J )
        mScene.removeComponent("raptorj");
    else if( code == sf::Keyboard::K)
        mScene.removeComponent("raptork");
    else if( code== sf::Keyboard::L )
        mScene.removeComponent("raptorl");
}
