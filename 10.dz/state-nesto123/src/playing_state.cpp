#include "playing_state.h"

// Implementacija PlayingState klase
#include "game.h"

PlayingState::PlayingState(Game * game, sf::Vector2u vec) : GameState(game, vec), mSnake(20), mWorld({800,600}){

}

void PlayingState::update(sf::Time dt){
    mSnake.update();
    mWorld.update( mSnake);



    if( mSnake.hasLost() == true )///////////////////////////////////// neki kurac fali
    {
        mpGame->set_or_getScore( mSnake.getScore() );
        if( mSnake.getScore() > 100 ){               //dobio
            mpGame->changeState( GameState::Won );
            mpGame->faster();
        }
        else                                        //spusio
            mpGame->changeState( GameState::Lost );
        mSnake.reset();
    }

}

void PlayingState::handlePlayerInput(sf::Keyboard::Key code){
    if( code == sf::Keyboard::Up ) mSnake.setDirection( Direction::Up );
    if( code == sf::Keyboard::Down ) mSnake.setDirection( Direction::Down );
    if( code == sf::Keyboard::Left ) mSnake.setDirection( Direction::Left );
    if( code == sf::Keyboard::Right ) mSnake.setDirection( Direction::Right );
}

void PlayingState::render(sf::RenderWindow & window){
    sf::RenderWindow *_mWindow = &window;
    World *_mWorld = &mWorld;

    _mWindow->clear();

    _mWindow->draw(mWorld);
    _mWindow->draw(mSnake);

    /**     display map     **/

    sf::RectangleShape line( sf::Vector2f( 760, 1 ) );

    line.setPosition( 20,20 );
    line.setFillColor( sf::Color::Black );

    for (  ; line.getPosition().y < window.getSize().y ; line.move( 0,20 ) )
        window.draw( line );

    line.setSize( sf::Vector2f( 1,560 ) );
    line.setPosition( 20,20 );

    for (  ; line.getPosition().x < window.getSize().x ; line.move( 20,0 ) )
        window.draw( line );
    /** **/

    /**     display score and remaining lives   **/

    string str( "Score: " );

    str += to_string( mSnake.getScore() );
    str += "  Remaining lives: ";
    str += to_string( mSnake.getLives() );

    sf::Text text;
    text.setString( str );
    text.setFont( font );
    text.setCharacterSize( 13 );
    text.setColor( sf::Color::Red );
    text.setPosition( sf::Vector2f(20,0) );
    window.draw( text );
    /** **/

}

