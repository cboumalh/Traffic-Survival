//Class that acts as game engine
#ifndef GAME_MAIN_HPP
#define GAME_MAIN_HPP

#define SFML_AUDIO_PROVIDES_MP3_DECODER
#include "Character_main.hpp"
#include "Car_main.hpp"
#include "Coin_main.hpp"
#include "Potion_main.hpp"
#include "Ghost_main.hpp"


class Game{
    private:
        sf::VideoMode videoMode;
        sf::RenderWindow *window;
        sf::View view;
        float width;
        float height;
        unsigned int points;
        sf::Texture backgroundTexture;
        sf::Sprite backgroundSprite;
        sf::Font font;
	    sf::Text guiText;
	    sf::Text endGameText;
        unsigned int clockRestartCounter;
        bool playerInvisible;

        bool endGame;
        bool nightModeOn;
        sf::Event sfmlEvent;
        sf::Clock clock;
        sf::Clock potionClock;
        float potionBreak;
        float speedupDuration;
        sf::Music highwaySound;
        sf::SoundBuffer coinBuffer;
        sf::Sound coinSound;
        sf::SoundBuffer potionBuffer;
        sf::Sound potionSound;

        Character *player;
        std::vector<Car*> cars;
        Coin *coin;
        Potion *potion;
        Ghost *ghost;

        void initVariables();
        void initWindow();
        void initView();
        void initCoin();
        void initPotion();
        void initCars();
        void initText();
        void initFonts();
        void initGhost();
        void initPlayer();
        void initCoinSound();
        void initPotionSound();
        void initBackgroundSprite();
        void initBackgroundTexture();
        void renderBackground();
        void initHighwaySound();
        void updateView();
        void handleVerticalCarCollisions();
        void handleHorizontalCarCollisions();
        void PlayerCarCollision();
        void updateGui();
        void updateMode();
        void renderGui(sf::RenderTarget* target);
        void updateEndGameText();
        void updatePlayerCoinCollision();
        void updatePlayerPotionCollision();
        void GhostPlayerCollision();
        void speedUpGame();
        void stopHighwaySound();
        void nightMode();
        void dayMode();
        void makePlayerInvisible();
        void makePlayerVisible();
        void renderPotion(sf::RenderTarget *target);
        void renderGhost(sf::RenderTarget *target);
        void updateGhost();

        
    public:
        Game();
        ~Game();

        const bool &getEndGame() const;

        void update();
        void render();
        const bool running() const;
        void pollEvents();
		
};



#endif
