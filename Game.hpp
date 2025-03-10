#ifndef GAME_HPP
#define GAME_HPP

#include "FaseStart.hpp"
#include "FaseLevel1.hpp"
#include "FaseLevel2.hpp"
#include "FaseLevel3.hpp"

#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"

class Game
{
public:
	Game(){}
	~Game(){}
	
	static void run()
	{
		SpriteBuffer buffer(270,61);
	
		FaseStart start("FaseStart",SpriteAnimado("rsc/BackgroundFloresta.anm",2));
		FaseLevel1 fase1("Fase1",SpriteAnimado("rsc/BackgroundFase1.anm",2));
		FaseLevel2 fase2("Fase2",SpriteAnimado("rsc/BackgroundFase2.anm",2));
		FaseLevel3 fase3("Fase3",SpriteAnimado("rsc/BackgroundFase3.anm",2));
		
		/*start.init();
		start.run(buffer);
		buffer.clear();
		
		fase1.init();
		fase1.run(buffer);
		buffer.clear();
		
		
		fase2.init();
		fase2.run(buffer);
		buffer.clear();
		*/
		fase3.init();
		fase3.run(buffer);
		buffer.clear();
	}

};

#endif // GAME_HPP

