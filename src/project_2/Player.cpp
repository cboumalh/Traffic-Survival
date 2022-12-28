#include "../../include/CUSTOM/Player_2.hpp"

Player::Player(float x, float y){
    this->shape.setPosition(x,y);

    this->initVariables();
    this->initShape();

}


Player::~Player(){

}


void Player::initVariables(){
    this->movementSpeed = 10.f;


}


void Player::initShape(){
    this->shape.setFillColor(sf::Color::Green);
    this->shape.setSize(sf::Vector2f(50.f, 50.f));
}


void Player::update(const sf::RenderTarget* target){
        
   
    this->updateInput();

    this->updateWindowBoundsCollision(target);
}

void Player::updateInput(){


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        this->shape.move(-this->movementSpeed, 0.f);
    }
    
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        this->shape.move(this->movementSpeed, 0.f);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        this->shape.move(0.f, -this->movementSpeed);
    }
    
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        this->shape.move(0.f, this->movementSpeed);
    }

}

void Player::render(sf::RenderTarget *target){
    
    target->draw(this->shape);
}


void Player::updateWindowBoundsCollision(const sf::RenderTarget *target){
    sf::FloatRect playerBounds = this->shape.getGlobalBounds();
    
    if(playerBounds.left <= 0.f)
        this->shape.setPosition(0, playerBounds.top);

    else if(playerBounds.left + playerBounds.width >= target->getSize().x)
        this->shape.setPosition(target->getSize().x - playerBounds.width, playerBounds.top);

    if(playerBounds.top <= 0.f)
        this->shape.setPosition(playerBounds.left, 0.f);

    else if(playerBounds.top + playerBounds.height >= target->getSize().y)
        this->shape.setPosition(playerBounds.left, target->getSize().y - playerBounds.height);

}
