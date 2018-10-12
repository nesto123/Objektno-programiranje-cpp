#include "sceneGraph.h"
// Implementacija

SceneNode::SceneNode(std::string name) : mName(name) ,mChildren(){

}

void SceneNode::addComponent( Ptr pnode ){
    mChildren.push_back( std::move(pnode));
}

void SceneNode::removeComponent(string const  &name ){      //      jos ne radi
    if( getName() == "base" )
        mChildren.back()->removeComponent(name);
    else{
        for( auto it = mChildren.begin() ; it != mChildren.end() ; ++it)
        {
            if( (*it)->getName() == name){
                if( (*it)->mChildren.size() != 0 ){
                    auto it2 = (*it)->mChildren.begin();
                    mChildren.push_back(std::move(*it2));
                    mChildren.erase(it);
                }
                else
                    mChildren.erase(it);
                return;
            }
            (*it)->removeComponent(name);
        }
    }
}

void SceneNode::update( sf::Time dt ){

}

void SceneNode::draw(sf::RenderTarget &target, sf::RenderStates states) const{

     if( getName() == "base" ){
        mChildren.front()->drawCurrent(target, states);
        mChildren.back()->draw(target,states);
     }
     else{
         drawCurrent(target,states);

         for( auto it = mChildren.begin() ; it != mChildren.end() ; ++it)
             (*it)->draw(target,states);
     }

}
void SceneNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const{}

////////////////////////////////////////////////////////////////////////////////////////////////////
//--BackgrNode--//
BackgrNode::BackgrNode(sf::Vector2u screen_size, std::string name) : SceneNode(name), window_size(screen_size){
    if( !texture.loadFromFile("Textures/Desert.png") )
        throw std::runtime_error("Cannot open file Desert.png");
    mSprite.setTexture( texture );

    float scalex = (float) window_size.x / texture.getSize().x;
    float scaley = (float) window_size.y / texture.getSize().y;

    mSprite.setScale( scalex, scaley );

}

void BackgrNode::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    this->drawCurrent(target, states);
}

void BackgrNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw( mSprite );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//--PlaneNode--//
PlaneNode::PlaneNode(string name) : SceneNode(name){
    if( name == "eagle" ){
        if( !texture.loadFromFile("Textures/Eagle.png") )
            throw std::runtime_error("Cannot open file Eagle.png");
        mSprite.setTexture( texture );
        mSprite.setPosition(500,500);

    }
    else if ( name == "raptorh" || name == "raptorj"||name == "raptork"||name == "raptorl"){
        if( !texture.loadFromFile("Textures/Raptor.png") )
            throw std::runtime_error("Cannot open file Raptor.png");
        mSprite.setTexture( texture );
        if(name == "raptorj")
            mSprite.setPosition(450,550);
        else if(name == "raptork")
            mSprite.setPosition(590,550);
        else if(name == "raptorh")
            mSprite.setPosition(400,600);
        else if(name == "raptorl")
            mSprite.setPosition(640,600);
    }
    else
        throw std::runtime_error("ERROR::PlaneNode::Constructor");
}

void PlaneNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const{
    target.draw(mSprite, states);
}
