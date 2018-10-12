#include "game.h"


// Implementacija Game klase dolazi ovdje.

Game::Game() : mWindow( sf::VideoMode(800,600), "SFLM windowW"), mSnake(20), mWorld({800,600})
{
//    mTimePerFrame = sf::seconds( 0.09 );
    mTimePerFrame = sf::seconds( 0.1 );

}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while ( mWindow.isOpen() ){
        processEvents();

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

void Game::processEvents()
{
    sf::Event event;
    while( mWindow.pollEvent(event) )
    {
        switch ( event.type ){
        case sf::Event::Closed:
            mWindow.close();
            break;
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code);
            break;
        }
    }
}

void Game::update ( sf::Time dt )
{
    //postavit brzinu zmije ----prije ovog
    mSnake.update();
    mWorld.update( mSnake );
    if ( mSnake.hasLost() == true )
        mSnake.reset();
}

void Game::render()
{
    sf::RenderWindow *_mWindow = &mWindow;
    World *_mWorld = &mWorld;

    _mWindow->clear();

    _mWindow->draw(mWorld);
    _mWindow->draw(mSnake);

    /**     display map     **/

    sf::RectangleShape line( sf::Vector2f( 760, 1 ) );

    line.setPosition( 20,20 );
    line.setFillColor( sf::Color::Black );

    for (  ; line.getPosition().y < mWindow.getSize().y ; line.move( 0,20 ) )
        mWindow.draw( line );

    line.setSize( sf::Vector2f( 1,560 ) );
    line.setPosition( 20,20 );

    for (  ; line.getPosition().x < mWindow.getSize().x ; line.move( 20,0 ) )
        mWindow.draw( line );


    /**     display score and remaining lives   **/

    string str( "Score: " );

    str += to_string( mSnake.getScore() );
    str += "  Remaining lives: ";
    str += to_string( mSnake.getLives() );

    sf::Font font;
    if ( !font.loadFromFile( "SansSerifRegular.ttf" ) )
        throw std::runtime_error("Cannot open file SansSerifRegular.ttf");

    sf::Text text;
    text.setString( str );
    text.setFont( font );
    text.setCharacterSize( 13 );
    text.setColor( sf::Color::Red );
    text.setPosition( sf::Vector2f(20,0) );
    mWindow.draw( text );
    /** **/

    _mWindow->display();

}

void Game::handlePlayerInput( sf::Keyboard::Key code )
{
    if( code == sf::Keyboard::Up ) mSnake.setDirection( Direction::Up );
    if( code == sf::Keyboard::Down ) mSnake.setDirection( Direction::Down );
    if( code == sf::Keyboard::Left ) mSnake.setDirection( Direction::Left );
    if( code == sf::Keyboard::Right ) mSnake.setDirection( Direction::Right );
}
