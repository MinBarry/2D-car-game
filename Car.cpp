#include "Car.h"
#include <iostream>

const double PI = 3.14159;

Car::Car(std::string fileName, sf::Vector2f location):Object(fileName, location)
{
    v = 0;
    a = 1;
    da= 2;
    vMax = 50;
    vMin = 0;
    lap =0;
    //car size 100x50
    sprite.setOrigin(50,25);
}

sf::Vector2f Car::update(){
    //update car sprite & velocity
    int angle = 10;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

        if(sprite.getRotation() < 270 && sprite.getRotation() >= 90){
            sprite.rotate(angle);
        } else if (sprite.getRotation() > 270 || sprite.getRotation()< 90) {
            sprite.rotate(-angle);

        }
    } else {

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

        if(sprite.getRotation() < 90 || sprite.getRotation() >= 270){
            sprite.rotate(angle);
        } else if(sprite.getRotation() > 90) {
            sprite.rotate(-angle);
        }
    } else {

    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){

        if(sprite.getRotation() < 360 && sprite.getRotation() >= 180){
            sprite.rotate(angle);
        } else if(sprite.getRotation() > 0 && sprite.getRotation() < 180){
            sprite.rotate(-angle);
        }
    } else {

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){

        if(sprite.getRotation() < 180 && sprite.getRotation() > 0){
            sprite.rotate(angle);
        } else if(sprite.getRotation() > 180 || sprite.getRotation() ==0){
            sprite.rotate(-angle);
        }
    } else {

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        if(v < vMax)
            v+=a;
    }else{
        if(v > vMin)
            v-=da;
        if(v< vMin)
            v= vMin;
    }
    //send x y to collision detection
    displacment = sf::Vector2f(v*cos(sprite.getRotation()*( PI /180)), v*sin(sprite.getRotation()*(PI/180)));
    std::cout << (int)sprite.getPosition().x<<","<< sprite.getPosition().y <<"\r";
    //std::cout << displacment.x<<","<< displacment.y <<"\r";
    return displacment;

}

void Car::move(){
    sprite.move(displacment);
}

bool Car::collisionDetection(int * map, int tilesize, unsigned int width){

    bool collision = false;
    int x = (sprite.getPosition().x + displacment.x) / tilesize;
    int y = (sprite.getPosition().y + displacment.y) / tilesize;

    int tile = map[(y*width)+x];


    switch (tile) {
        case 0:
                 if((int)sprite.getPosition().x <= x*tilesize)
                    lap++;
            break;
        case 1:
                collision = false;
            break;

        case 2:
        case 3:
                displacment = sf::Vector2f(0,0);
                v=v/2;


            break;


    }

    return collision;

}
Car::~Car()
{
    //dtor
}
