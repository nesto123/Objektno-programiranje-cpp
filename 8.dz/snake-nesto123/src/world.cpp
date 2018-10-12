#include "world.h"
#include <ctime>
#include <random>
//#include
// Implementacija klase World dolazi ovdje.


void World::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    for(int i=0; i<4; ++i)
      target.draw(mBounds[i]);
    target.draw(mApple);
}


World::World( sf::Vector2i windowSize ) : mWindowSize( windowSize ), mBlockSize(20)
{

    mBounds[0].setSize( {20,600} );
    mBounds[1].setSize( {800,20} );
    mBounds[2].setSize( {20,600} ); mBounds[2].setPosition( {780,0} );
    mBounds[3].setSize( {800,20} ); mBounds[3].setPosition( {0,580} );

    for ( unsigned i = 0 ; i < 4 ; ++i )
        mBounds[i].setFillColor( sf::Color( 100, 250, 50 ) );

    mApple.setRadius( (mBlockSize+1) / 2 );
    respawnApple();

    /*      original - bez slike
     *
     *     mApple.setFillColor( sf::Color::Red );
     */

    /**     Dodatak za jabuku sa slikom     **/
    if( !tex.loadFromFile("apple.png") )
        throw std::runtime_error("Cannot open file apple.png");
    mApple.setTexture(&tex);
    /** **/
}

unsigned rand( unsigned min, unsigned max , unsigned step)
{
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased
    unsigned random_integer = uni(rng);
    //std::uniform_int_distribution<int> uni2(20,580); // guaranteed unbiased

    if( random_integer % step == 0 )
        return random_integer;
    else{
        unsigned temp = random_integer % step;
        if( random_integer - temp >= min )
            return ( random_integer - temp );
        else
            return  ( random_integer + step - temp );
    }
}

void World::respawnApple()      //  rjesit jos koliziju sa zmijom
{
    /*
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(10,780); // guaranteed unbiased
    std::uniform_int_distribution<int> uni2(20,580); // guaranteed unbiased
    int random_integer1 = uni(rng), random_integer2 = uni2(rng);
    std::cout<< random_integer1<<","<<random_integer2<<endl;
    mApple.setPosition( random_integer1, random_integer2 );
    */
    //int random_integer1 = rand( 20, 760, 20 ), random_integer2 = rand( 20, 560, 20);
    //std::cout<< random_integer1<<","<<random_integer2<<endl;
    //mApple.setPosition( random_integer1, random_integer2 );

    mApple.setPosition( rand( 20, 760, mBlockSize ), rand( 20, 560, mBlockSize));
}



void World::update( Snake &snake )
{
    //bool kolizija = false;
    auto temp = snake.getPosition();
    if( temp.x >= 780 || temp.x < 20 || temp.y < 20 || temp.y >= 580 )
        snake.lose();
    else if( temp.x == mApple.getPosition().x && mApple.getPosition().y == temp.y){
      //  do{
            respawnApple();
        //}while()
        snake.increaseScore();
        snake.extend();
    }
}
