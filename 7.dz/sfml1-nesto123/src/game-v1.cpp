#include "game-v1.h"

Game::Game() : mWindow(sf::VideoMode(800,600), "Game-v1"){
   if (!mTexture.loadFromFile("cb.bmp"))
        throw std::runtime_error("Cannot open file cb.bmp!");


   mSprite.setTexture(mTexture);
   mSpeed = 500;

   mTimePerFrame = sf::seconds(0.01666666666f);             //1/60


   ///      za I. zadatak

   shape.setRadius(50);
   //shape.setFillColor(sf::Color(100, 250, 50));
   shape.setOutlineThickness(5);
   shape.setOutlineColor(sf::Color(250, 150, 100));
   shape.setTexture(&mTexture); // texture is a sf::Texture
   shape.setTextureRect(sf::IntRect(10, 10, 100, 100));
   shape.setPosition(100,100);

}

// game-loop je sada u metodi run()
void Game::run(){
    sf::Clock clock; // defaultni konstruktor starta sat
    // vrijeme od zadnjeg poziva funkciji update()
    sf::Time timeSinceLastUpdate = sf::Time::Zero;



    while(mWindow.isOpen())
    {
       processEvents();
       // stavi clock na nulu i vrati protekli interval
       timeSinceLastUpdate += clock.restart();
       // updatiraj eventualno više puta ako je iscrtavanje bilo sporo
       while(timeSinceLastUpdate > mTimePerFrame)
       {
          timeSinceLastUpdate -= mTimePerFrame;
          processEvents();
          update(mTimePerFrame);
       }
       render();
    }
}


// obrada događaja
void Game::processEvents(){
      sf::Event event;
      while( mWindow.pollEvent(event) ){
        if( event.type == sf::Event::Closed )
        {
            mWindow.close();
            break;
        }

        if( event.type == sf::Event::KeyPressed )
        {
            handlePlayerInput( event.key.code, true );
            break;
        }
        if( event.type == sf::Event::KeyReleased)
        {
            handlePlayerInput( event.key.code, false );
            break;
        }

      }
}

void Game::handlePlayerInput( sf::Keyboard::Key code, bool isPressed){
    if( code == sf::Keyboard::Up)    mIsMovingUp    = isPressed;
    if( code == sf::Keyboard::Down)  mIsMovingDown  = isPressed;
    if( code == sf::Keyboard::Left)  mIsMovingLeft  = isPressed;
    if( code == sf::Keyboard::Right) mIsMovingRight = isPressed;
}

// Pomicanje figure
void Game::update(sf::Time const & dt){
    sf::Vector2f movement(0.f, 0.f);  // brzina
    if(mIsMovingUp)
        movement.y -= mSpeed;
    if(mIsMovingDown)
        movement.y += mSpeed;
    if(mIsMovingLeft)
        movement.x -= mSpeed;
    if(mIsMovingRight)
        movement.x += mSpeed;

    mSprite.move(movement * dt.asSeconds());
}

// iscrtavanje
void Game::render(){
    mWindow.clear();
    //mWindow.draw(mSprite);
mWindow.draw(shape);
   /** za I. zadatak
    *mWindow.draw(shape);
    *
   */


    mWindow.display();
}
