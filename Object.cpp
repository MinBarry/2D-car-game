#include "Object.h"

Object::Object(std::string filename, sf::Vector2f location)
{
    if(!texture.loadFromFile(filename))
    {
        //error handle
        exit(-1);
    }
    sprite.setTexture(texture);
    sprite.setPosition(location);
    source.x= 0;
    source.y= 0;


}

void Object::draw(sf::RenderWindow &window){
    window.draw(sprite);

}

Object::~Object()
{
    //dtor
}
