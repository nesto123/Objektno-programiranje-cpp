#include <SFML/Graphics.hpp>
#include "game-v1.h"
#include <iostream>
#include <cmath>
using namespace std;

class Game2{
public:
    Game2();
    void run();
private:
    // Procesiraj događaje
    void processEvents();
    // konstruiraj novo stanje igre
    void update(sf::Time const & dt);
    // iscrtaj novo stanje
    void render();
private:
    sf::RenderWindow mWindow;
    sf::Texture      sunce_tex, zemlja_tex, avion_tex;
    sf::Sprite       Sunce, zemlja, avion, shape1;
    sf::CircleShape   shape2, shape3;
   // sf::CircleShape  shape;
    sf::Transform transform, transform2;
    float alpha, beta /*kut za zemlju, avion*/, radijus_zemlja, radijus_avion;

    bool mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight;
    void handlePlayerInput( sf::Keyboard::Key code, bool isPressed);
    int mSpeed;
    sf::Time mTimePerFrame;
};

Game2::Game2() : mWindow(sf::VideoMode(1300,900), "Game-v1"){
   if (!sunce_tex.loadFromFile("SunRed.png"))
        throw std::runtime_error("Cannot open file SunRed.png!");
   if (!zemlja_tex.loadFromFile("planet1.png"))
        throw std::runtime_error("Cannot open file planet1.png!");
   if (!avion_tex.loadFromFile("Plane.png"))
        throw std::runtime_error("Cannot open file Plane.png!");

  // Sunce.setTexture(sunce_tex);

   //mSpeed = 0.00001;
   //mTimePerFrame = sf::seconds(0.01666666666f);

   //shape1.setRadius(100);
   //shape1.setFillColor(sf::Color(100, 250, 50));shape2.setRadius(30); shape3.setRadius(15);
   //shape1.setOutlineThickness(5);   shape2.setOutlineThickness(5);
   //shape1.setOutlineColor(sf::Color(250, 150, 100));
   shape1.setTexture(sunce_tex);   //shape2.setTexture(&zemlja_tex);     shape3.setTexture(&avion_tex);   // texture is a sf::Texture
   //shape1.setPosition(400,300);
   //shape1.setPosition(sf::Vector2f(800/2,600/2));

   zemlja.setTexture( zemlja_tex );
   avion.setTexture( avion_tex );
   beta = alpha = 0.0;
   radijus_zemlja = 300; radijus_avion = 90;

/*
   sf::Rect<float> size = shape1.getGlobalBounds( );

   shape1.setOrigin( sf::Vector2f ( size.width / 2, size.height / 2 ) );
   size = shape2.getGlobalBounds( );
   shape2.setOrigin( sf::Vector2f ( size.width / 2, size.height / 2 ) );
   size = shape3.getGlobalBounds( );
   shape3.setOrigin( sf::Vector2f ( size.width / 2, size.height / 2 ) );
*/
    avion.scale( 0.1, 0.1 );
    zemlja.scale ( 0.2, 0.2 );
    shape1.scale( 0.2, 0.2);
    zemlja.setOrigin( 250, 250 );
    zemlja.setPosition( 250, 500);
    shape1.setOrigin( 400, 400 );
    shape1.setPosition( 600, 500 );
    avion.setOrigin( 221.5, 151 );
    avion.setPosition( 200, 250);
    avion.rotate( 90 );

/*
   sf::Vector2f position = shape1.getPosition( );
        cout << position.x << ", " << position.y << endl;
   shape2.setPosition( position.x+200, position.y );
        cout << position.x+200 << ", " << position.y << endl;
   position = shape2.getPosition( );
   shape3.setPosition( position.x+60, position.y);
*/
  // transform.rotate(1,shape1.getPosition( ) );




}

void Game2::run(){
    sf::Clock clock; // defaultni konstruktor starta sat
    // vrijeme od zadnjeg poziva funkciji update()
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while(mWindow.isOpen())
    {
       processEvents();
       // stavi clock na nulu i vrati protekli interval
       //timeSinceLastUpdate += clock.restart();
       // updatiraj eventualno više puta ako je iscrtavanje bilo sporo
       //while(timeSinceLastUpdate > mTimePerFrame)
       //{
       //   timeSinceLastUpdate -= mTimePerFrame;
       //   processEvents();
       mTimePerFrame = clock.restart( );
          update(mTimePerFrame);
       //}
       render();
    }
}
void Game2::processEvents(){
      sf::Event event;
      while( mWindow.pollEvent(event) ){
        if( event.type == sf::Event::Closed )
        {
            mWindow.close();
            break;
        }
      }
}
void Game2::update(sf::Time const & dt){
    sf::Vector2f movement(0.f, 0.f), temp;  // brzina

    zemlja.rotate( -72 * dt.asSeconds( ) );
    alpha -= ( M_PI / 30 ) * dt.asSeconds( );
    temp = shape1.getPosition( );
    movement.x = temp.x + radijus_zemlja * cos( alpha );
    movement.y = temp.y + radijus_zemlja * sin( alpha );
    zemlja.setPosition( movement );

 /*       sf::Vector2f temp, position_shape1 = shape1.getPosition( ), old_origin = shape2.getPosition( );
  * shape2.setOrigin( position_shape1 );
    shape2.rotate( -1 );
    old_origin.x = position_shape1.x + 200*cos( shape2.getRotation( ) * M_PI / 180 );
    old_origin.y = position_shape1.y + 200*sin( shape2.getRotation( ) * M_PI / 180 );

    transform.rotate(-1,shape1.getPosition( ) );

    if(kut>360)kut-=360;
    temp.x = position_shape1.x + 200*cos( kut * M_PI / 180 );
    temp.y = position_shape1.y + 200*sin( kut * M_PI / 180 );


    transform2.rotate(1, shape2.getPosition() );
    kut+=1;

    size = shape2.getGlobalBounds( );
    if(++i==50 || i==200||i==100||i==250||i==300)cout<<"Nakon poziva rotate( ):"<<shape2.getRotation( )<<", "<<temp.y<<endl
                              <<"Old origin : "<<old_origin.x<<", "<<old_origin.y<<endl;
    /*temp=shape2.getPosition() ;
    if(++i==50 || i==100)cout<<"Nakon poziva rotate( ):"<<temp.x<<", "<<temp.y<<endl
                          <<"Old origin : "<<old_origin.x<<", "<<old_origin.y<<endl;
    */
  //  shape2.setOrigin( old_origin );

    beta += M_PI * dt.asSeconds( );
    avion.rotate( 180 * dt.asSeconds( ) );

    temp = zemlja.getPosition( );
    movement.x = temp.x + radijus_avion * cos( beta );
    movement.y = temp.y + radijus_avion * sin( beta );
    avion.setPosition( movement );
}
void Game2::render(){
    mWindow.clear( );
    mWindow.draw( shape1 );
    mWindow.draw( zemlja );
    mWindow.draw( avion );
 //   mWindow.draw( shape2 , transform);
    mWindow.display( );
}


int main()
{
    ///         ZADATAK     II.
      Game2 game2;
      game2.run();

   ///          ZADATAK     I.
   //  Game game;
   //  game.run();


    return 0;
}


/**         INITIAL TEST            **/
/*
int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML window");
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("cb.bmp"))
        throw std::runtime_error("Cannot open file cb.bmp!");
    sf::Sprite sprite(texture);

	// Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(sprite);
        // Update the window
        window.display();
    }

    return 0;
}
*/
