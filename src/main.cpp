#include "../include/CUSTOM/Game.hpp"


int main(){
    //Init game engine
    Game game;


	while(game.running()){
		
        game.update();

        game.render();

	}


    return 0;
}

