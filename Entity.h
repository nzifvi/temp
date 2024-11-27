#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Entity.h"
#include <string>

class Entity {
private:
        int width;
        int height;
        int area;
        int currentXPos;
        int currentYPos;
        sf::Texture entityTexture;
        sf::RectangleShape entityBox;
        sf::Sprite entitySprite;
        bool canCollide;

        sf::Texture loadTexture(int loadWhat);
public:
        Entity(int width, int height, int loadWhat, bool canCollide);
        Entity(int width, int height, int xPos, int yPos, int loadWhat, bool canCollide);
        sf::Sprite getSprite();
        sf::RectangleShape getEntityRect();
        sf::Texture getEntityTexture();
        bool updatePos(int xPos, int yPos);
        ~Entity();
};
