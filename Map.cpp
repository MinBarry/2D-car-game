#include "Map.h"

Map::Map(std::string fileName, sf::Vector2f location) : Object(fileName, location)
{
    //outer.resize(12);
    /*outer.setPrimitiveType(sf::LinesStrip);
    inner.setPrimitiveType(sf::LinesStrip);
    level1[0] = sf::Vector2f(200,800);  level1[1] = sf::Vector2f(200,400);   level1[2] = sf::Vector2f(400,200);
    level1[3] = sf::Vector2f(1200,200); level1[4] = sf::Vector2f(1400,400);  level1[5] = sf::Vector2f(1400,800);
    level1[6] = sf::Vector2f(1200,1000);level1[7] = sf::Vector2f(400,1000);  level1[8] = sf::Vector2f(200,800);
    createLevel(level1);
    currentLevel = level1;*/
}

void Map::createLevel(sf::Vector2f level []){

    int vertexCount = 9;
    outer.resize(vertexCount);
    inner.resize(vertexCount);
    for (int i=0; i<vertexCount; i++){
        outer[i].position = level1[i];
        inner[i].position = sf::Vector2f((level1[i].x*0.5)+400,(level1[i].y*0.5)+300);
        outer[i].color = sf::Color::White;
    }

}

sf::Vector2f Map::update(){
    //update map sprite



}

Map::~Map()
{
    //dtor
}
