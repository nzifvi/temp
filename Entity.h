#include "Entity.h"

const enum {
        PLAYER = 1,
        NPC_TYPE_MALE_1,
        NPC_TYPE_MALE_2,
        NPC_TYPE_MALE_3,
        NPC_TYPE_FEMALE_1,
        NPC_TYPE_FEMALE_2,
        NPC_TYPE_FEMALE_3,
};

/*
------------------------------------------------------------------------------
||---||---||---||---||---||---|| PRIVATE AREA ||---||---||---||---||---||---||
-----------------------------------------------------------------------------:
*/

sf::Texture Entity::loadTexture(int loadWhat) {
        std::string textureToLoad;
        switch (loadWhat) {
        case PLAYER:
                textureToLoad = "Assets/Player/testPlayer.png";
                break;
        default:
                std::cout << "! FATAL ERROR: loadWhat value, " << loadWhat << " , is an undefined texture, terminating program\n";
                exit(2);
        }
        std::cout << textureToLoad << "\n";
        if (!entityTexture.loadFromFile(textureToLoad)) {
                std::cout << "! FATAL ERROR: Entity loadTexture() unable to load " + textureToLoad + ", terminating program\n";
                exit(1);
        }
}

/*
-----------------------------------------------------------------------------
||---||---||---||---||---||---|| PUBLIC AREA ||---||---||---||---||---||---||
-----------------------------------------------------------------------------
*/
Entity::Entity(int width, int height, int loadWhat, bool canCollide) {
        this->width = width;
        this->height = height;
        this->area = width * height;
        this->canCollide = canCollide;

        currentXPos = 0;
        currentYPos = 0;

        entityBox.setSize(sf::Vector2f(width, height));
        entityBox.setFillColor(sf::Color::Cyan);

        loadTexture(loadWhat);
        entitySprite.setTexture(entityTexture);

        updatePos(currentXPos, currentYPos);
}

Entity::Entity(int width, int height, int xPos, int yPos, int loadWhat, bool canCollide) {
        this->width = width;
        this->height = height;
        this->area = width * height;
        this->canCollide = canCollide;

        currentXPos = xPos;
        currentYPos = yPos;

        entityBox.setSize(sf::Vector2f(width, height));
        entityBox.setFillColor(sf::Color::Cyan);

        loadTexture(loadWhat);
        entitySprite.setTexture(entityTexture);

        updatePos(currentXPos, currentYPos);
}

sf::Sprite Entity::getSprite() {
        return entitySprite;
}

sf::RectangleShape Entity::getEntityRect() {
        return entityBox;
}

sf::Texture Entity::getEntityTexture() {
        return entityTexture;
}

bool Entity::updatePos(int xPos, int yPos) {
        entitySprite.setPosition(xPos, yPos);
        return true;
}

Entity::~Entity() {

}
