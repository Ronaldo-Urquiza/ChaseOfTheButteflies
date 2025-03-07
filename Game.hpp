#ifndef GAME_HPP
#define GAME_HPP

#include "FaseStart.hpp"

#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"

class Game
{
public:
	Game(){}
	~Game(){}
	
	static void run()
	{
		SpriteBuffer buffer(250,65);
	
		FaseStart start("FaseStart",SpriteAnimado("rsc/BackgroundFloresta.anm",2));
		
		start.init();
		start.run(buffer);
	}

};

#endif // GAME_HPP
