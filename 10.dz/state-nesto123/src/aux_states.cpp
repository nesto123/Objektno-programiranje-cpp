#include "aux_states.h"

// Implementacija pomoćnih stanja.

//   mozda ovo treba maknut
#include "game.h"

///     GameState::      ///


///     WelcomeState::      ///
WelcomeState::WelcomeState(Game * game, sf::Vector2u vec) : GameState(game, vec) {

    string str1("Snake game \n by Nesto123 "), str2("Press any key to continue..");

    txt1.setFont(font);                         txt2.setFont(font);
    txt1.setString( str1 );                     txt2.setString(str2);
    txt1.setCharacterSize( 50 );                txt2.setCharacterSize(26);
    txt1.setColor( sf::Color::White );          txt2.setColor( sf::Color::White );

    sf::FloatRect txt1_rect = txt1.getLocalBounds(), txt2_rect = txt2.getGlobalBounds();

    txt1.setOrigin( txt1_rect.width / 2, txt1_rect.height / 2);                  txt2.setOrigin( txt1_rect.width / 2, txt1_rect.height / 2);
    txt1.setPosition( sf::Vector2f( wiondowSize.x / 2, wiondowSize.y / 2 - 50) );     txt2.setPosition( sf::Vector2f( wiondowSize.x / 6*4, wiondowSize.y / 6 * 5.7) );
}

void WelcomeState::update(sf::Time dt){}
void WelcomeState::handlePlayerInput(sf::Keyboard::Key code){
    mpGame->changeState( GameState::Playing );
}
void WelcomeState::render(sf::RenderWindow & window){
    window.draw(txt1);
    window.draw(txt2);
}


///     ExitingState::      ///
ExitingState::ExitingState(Game * game, sf::Vector2u vec) : GameState(game, vec),str1("Game over ")  {

    txt1.setFont(font);
    txt1.setString( str1 );
    txt1.setCharacterSize( 50 );
    txt1.setColor( sf::Color::White );

    sf::FloatRect txt1_rect = txt1.getLocalBounds();

    txt1.setOrigin( txt1_rect.width / 2, txt1_rect.height / 2);
    txt1.setPosition( sf::Vector2f( wiondowSize.x / 2, wiondowSize.y / 2) );
}

void ExitingState::update(sf::Time dt){
    static sf::Time time = sf::seconds( 3.0f );

    time -= dt;
    temp = int (time.asSeconds() + 0.5);            //t.d. zaokruzivanje radi
    txt1.setString( str1 + std::to_string(temp));

}
void ExitingState::handlePlayerInput(sf::Keyboard::Key code){}
void ExitingState::render(sf::RenderWindow & window){
    if( temp == -1 )
        window.close();
    window.draw(txt1);
}



///     WonState::      ///
WonState::WonState(Game * game, sf::Vector2u vec) : GameState(game, vec), str1("You won! The score = ") {
    string  str2("Hit C to continue, X to exit");

    txt1.setFont(font);                         txt2.setFont(font);
    txt1.setString( str1 );                     txt2.setString(str2);
    txt1.setCharacterSize( 50 );                txt2.setCharacterSize(26);
    txt1.setColor( sf::Color::White );          txt2.setColor( sf::Color::White );

    sf::FloatRect txt1_rect = txt1.getLocalBounds(), txt2_rect = txt2.getGlobalBounds();

    txt1.setOrigin( txt1_rect.width / 2, txt1_rect.height / 2);                  txt2.setOrigin( txt1_rect.width / 2, txt1_rect.height / 2);
    txt1.setPosition( sf::Vector2f( wiondowSize.x / 2, wiondowSize.y / 2 - 200 ) );     txt2.setPosition( sf::Vector2f( wiondowSize.x / 6*4, wiondowSize.y / 6 * 5.7) );

    ///     za sliku
    if( !texture.loadFromFile("youwon.png") )
        throw std::runtime_error("Cannot open file youwon.png");
    sprite.setTexture( texture );
    sprite.setPosition( sf::Vector2f(200,200));
    sprite.setColor(sf::Color::White);
}

void WonState::update(sf::Time dt){
    txt1.setString( str1 + std::to_string( mpGame->set_or_getScore() ) );
}
void WonState::handlePlayerInput(sf::Keyboard::Key code){
    if( code == sf::Keyboard::X )
        mpGame->changeState( GameState::Exiting );
    if( code == sf::Keyboard::C )
        mpGame->changeState( GameState::Playing );
}
void WonState::render(sf::RenderWindow & window){
    window.draw(txt1);
    window.draw(txt2);
    /// za sliku
        window.draw(sprite);
}

///     LostState::      ///
LostState::LostState(Game * game, sf::Vector2u vec) : GameState(game, vec), str1("You lost! The score = "){
    string  str2("Hit C to continue, X to exit");

    txt1.setFont(font);                         txt2.setFont(font);
    txt1.setString( str1 );                     txt2.setString(str2);
    txt1.setCharacterSize( 40 );                txt2.setCharacterSize(26);
    txt1.setColor( sf::Color::White );          txt2.setColor( sf::Color::White );

    sf::FloatRect txt1_rect = txt1.getLocalBounds(), txt2_rect = txt2.getGlobalBounds();

    txt1.setOrigin( txt1_rect.width / 2, txt1_rect.height / 2);                  txt2.setOrigin( txt1_rect.width / 2, txt1_rect.height / 2);
    txt1.setPosition( sf::Vector2f( wiondowSize.x / 2 , wiondowSize.y / 2 -200) );     txt2.setPosition( sf::Vector2f( wiondowSize.x / 6*4, wiondowSize.y / 6 * 5.7) );

    /// za sliku
        if( !texture.loadFromFile("loser1.png") )
            throw std::runtime_error("Cannot open file loser1.png");
        sprite.setTexture( texture );
        sprite.setPosition( sf::Vector2f(200,200));
        sprite.setColor(sf::Color::White);
}


void LostState::update(sf::Time dt){
    txt1.setString( str1 + std::to_string( mpGame->set_or_getScore() ) );

}
void LostState::handlePlayerInput(sf::Keyboard::Key code){
    if( code == sf::Keyboard::X )
        mpGame->changeState( GameState::Exiting );
    if( code == sf::Keyboard::C )
        mpGame->changeState( GameState::Playing );
}
void LostState::render(sf::RenderWindow & window){
    window.draw(txt1);
    window.draw(txt2);
    /// za sliku
        window.draw(sprite);
}
