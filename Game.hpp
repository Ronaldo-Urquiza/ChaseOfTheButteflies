#ifndef GAME_HPP
#define GAME_HPP

#include "FaseStart.hpp"
#include "FaseLevel1.hpp"

#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"

class Game
{
public:
	Game(){}
	~Game(){}
	
	static void run()
	{
		SpriteBuffer buffer(250,61);
	
		FaseStart start("FaseStart",SpriteAnimado("rsc/BackgroundFloresta.anm",2));
		FaseLevel1 fase1("Fase1",SpriteAnimado("rsc/BackgroundFase1.anm",2));
		
		fase1.init();
		fase1.run(buffer);
		buffer.clear();
		
		//fase1.init();
		//int ret1 = fase1.run(buffer);
		
	}

};

#endif // GAME_HPP

