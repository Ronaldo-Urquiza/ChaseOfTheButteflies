#include "FaseStart.hpp"

#include <iostream>

void FaseStart::init()
{	
	//Objetos de jogo
	hero = new ObjetoDeJogo("Hero",SpriteAnimado("rsc/heroWalkingRight.anm",1),20,160);
	objs.push_back(hero);
	
	tapetePortal = new ObjetoDeJogo("TapetePortal",SpriteBuffer(2,20),22,215);
	objs.push_back(tapetePortal);
}

unsigned FaseStart::run(SpriteBuffer &screen)
{
	std::string ent;
	
	//padrão
	draw(screen);
	system("clear");
	show(screen);
	
	int teste = 0;
	
	while (true)
	{
		//lendo entrada
		getline(std::cin,ent);
		
		//processando entradas
		int posL = hero->getPosL(), posC = hero->getPosC();
		
		//checando portal
		if (hero->colideCom(*tapetePortal)){
			int teste = 1;
			return Fase::LEVEL_COMPLETE;
		}
		
		if (ent == "w" && hero->getPosL() > 10 && teste == 0)
			hero->moveUp(2);
		else if (ent == "s" && hero->getPosL() < screen.getAltura() - 15 && teste == 0)
			hero->moveDown(2);
		else if (ent == "a" && hero->getPosC() > 12 && teste == 0)
			hero->moveLeft(5);
		else if (ent == "d" && hero->getPosC() < screen.getLargura() - hero->getSprite()->getLargura() - 13 && teste == 0)
			hero->moveRight(8);
		else if (ent == "q")
			return Fase::END_GAME;
		
			
		update();
		draw(screen);
		system("clear");
		show(screen);
		screen.clear();
	}
	
	return Fase::END_GAME; // não necessário
}