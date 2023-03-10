#ifndef CAR_MAIN_H
#define CAR_MAIN_H

#include <iostream>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Car {

    private:
        sf::Sprite sprite;
        sf::Texture texture;
        float carSpeed;
        float maxCarSpeed;
        char direction;
        float x_pos;
        float y_pos;
        bool stopSprite;

        void initVariables(float &x_pos, float &y_pos, float &carSpeed, const char &direction);
        void initTexture(const std::string &texturePath);
        void initSpritePos();
        void initSprite();
        void updateSprite();

    public:
        Car(const std::string texturePath, float x_pos, float y_pos, float carSpeed, const char direction);
        ~Car();

        void update(const sf::RenderTarget* target);
        void render(sf::RenderTarget* target);
        void updateWindowBoundsCollision(const sf::RenderTarget *target);
        const bool checkCarCollision(Car &other_car) const;
        const sf::Sprite & getSprite();
        const float getCarSpeed() const;
        void setStopSprite(bool value);
        const float getCarDirection() const;
        const bool getStopSpriteVal() const;
        void incrementCarSpeed();


};




#endif