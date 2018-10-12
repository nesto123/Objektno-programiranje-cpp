#include "snake.h"

// Implementacija Snake klase.
//  Implementacija klase Snake dolazi ovdje.
Snake::Snake(int blockSize) : msize( blockSize ), mlives( 3 ), mlost( false ), mscore( 0 ), mdir( Direction::None), last_removed(0,0)
{
    mbodyRect.setSize( {(float)msize,(float)msize} );
    mbodyRect.setFillColor( sf::Color::Yellow );

    SnakeSegment segment( 40, 40 );
    mSnakeBody.push_back( segment );


}

sf::Vector2i Snake::getPosition()       //done
{
    sf::Vector2i vec( mSnakeBody[0].x, mSnakeBody[0].y );
    return vec;
}

void Snake::extend()
{
    //if ( mSnakeBody.size() == 1){
        last_removed.x = mSnakeBody[0].x; last_removed.y = mSnakeBody[0].y;
        if( mdir == Direction::Down )
            last_removed.y -= msize;
        else if ( mdir == Direction::Up )
            last_removed.y += msize;
        else if ( mdir == Direction::Right )
            last_removed.x -= msize;
        else if( mdir == Direction::Left )
            last_removed.x += msize;
    //}
   // else{

    //}
    mSnakeBody.push_back(last_removed);
}

void Snake::reset()
{
    mlives = 3;
    mlost = false;
    mscore = 0;
    mdir = Direction::None;

    while ( mSnakeBody.size() )
        mSnakeBody.pop_back();
    SnakeSegment segment( 40, 40 );
    mSnakeBody.push_back( segment );
    last_removed.x = last_removed.y = 0;
}

void Snake::update()
{
   checkCollision();
   move();
   checkCollision();
}

void Snake::cut(int n)      //done
{
    while ( n-- )
        mSnakeBody.pop_back();
}

void Snake::checkCollision()        // negdje provjerit za sl mlives == 0  kad je izgubljena igra
{
    for ( unsigned i = 1 ; i < mSnakeBody.size() ; ++i )
    {
        if( mSnakeBody[0].x == mSnakeBody[i].x && mSnakeBody[0].y == mSnakeBody[i].y )
        {
            cut( mSnakeBody.size() - i );
            mlives--;
            if( mlives == 0 )
                mlost = true;
            return;
        }
    }
}

void Snake::move()  //done
{
    if( mdir == Direction::None )   //ostaje na mjestu
        return;
    // save za last_removed
    last_removed.x = mSnakeBody[mSnakeBody.size()-1].x; last_removed.y = mSnakeBody[mSnakeBody.size()-1].y;
    // move za ostale --
    for ( unsigned i =  mSnakeBody.size() - 1 ; i >= 1; --i){
        mSnakeBody[i].x = mSnakeBody[i-1].x;
        mSnakeBody[i].y = mSnakeBody[i-1].y;
    }
    //  move za prvog
    if( mdir == Direction::Up )
        mSnakeBody[0].y -= msize;
    else if( mdir == Direction::Left )
        mSnakeBody[0].x -= msize;
    else if( mdir == Direction::Right)
        mSnakeBody[0].x += msize;
    else // Down
        mSnakeBody[0].y += msize;
}

void Snake::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    mbodyRect.setFillColor( sf::Color::Yellow );
    for ( unsigned i = 0 ; i < mSnakeBody.size() ; ++i ){
        mbodyRect.setPosition( mSnakeBody[i].x, mSnakeBody[i].y );
        target.draw( mbodyRect );
        mbodyRect.setFillColor( sf::Color::Cyan );
    }

}
