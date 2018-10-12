#ifndef SCENE_GRAPH_IS_INCLUDED
#define SCENE_GRAPH_IS_INCLUDED

#include <memory>
#include <list>

#include <iostream>


#include <SFML/Graphics.hpp>

using namespace std;

class SceneNode : public sf::Transformable, public sf::Drawable
{
    public:
        SceneNode(std::string name);        //glavni konstruktor

        using Ptr = std::unique_ptr<SceneNode>;
              
        void addComponent(Ptr pnode);
        void removeComponent(std::string const & name);

        void update(sf::Time dt);
        std::string getName() const { return mName; }
    private:
        virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
        // Implementacijski detalji
    //
        virtual void drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const;


        std::list<Ptr> mChildren;
        std::string    mName;

        //
        Ptr     mParent;
};

// BackgrNode služi za crtanje background-a. On se ne miče
// niti ne centriramo njegov Sprite.
class BackgrNode : public SceneNode {
    public:
      // ...
    BackgrNode(sf::Vector2u screen_size, std::string name="background");

    private:
        virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

        virtual void drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const;
        sf::Sprite   mSprite;
        sf::Texture texture;

        sf::Vector2u window_size;

};

// SpriteNode služi za crtanje aviona.
class  PlaneNode : public SceneNode{
    public:
        // ....     
    PlaneNode(string name);
        void setVelocity(sf::Vector2f v) {mVelocity = v; }
        void setVelocity(float vx, float vy) { mVelocity.x = vx; mVelocity.y = vy; }
        sf::Vector2f getVelocity() const { return mVelocity; }
    private:
        virtual void drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const;
	// ........
        sf::Sprite   mSprite;
        sf::Vector2f mVelocity;
        sf::Texture texture;

};


#endif

