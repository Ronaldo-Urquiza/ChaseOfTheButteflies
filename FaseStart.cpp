#include "FaseStart.hpp"

#include <iostream>
#include <thread>  // Adiciona essa linha no topo do arquivo
#include <chrono>  // Para definir a duração do sleep
#include "ASCII_Engine/TextBox.hpp"

void FaseStart::init()
{	
	//Objetos de jogo
	hero = new ObjetoDeJogo("Hero",SpriteAnimado("rsc/heroWalkingRight.anm",1),20,10);
	objs.push_back(hero);
	
	tapetePortal = new ObjetoDeJogo("TapetePortal",SpriteBuffer(2,20),22,215);
	objs.push_back(tapetePortal);
}

unsigned FaseStart::run(SpriteBuffer &screen)
{
	std::string ent;
	
	TextBox caixaTexto(50, 3); // Largura 30, Altura 3
	
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
			
			caixaTexto.setText("A energia do portal te consome por completo, você sente seu corpo sendo puxado para outro lugar...");
			caixaTexto.show();
			
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("Talvez seja hora de partir, deixar tudo para trás...");
			caixaTexto.show();
			
			system("clear");
			screen.clear();
			show(screen);
			
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			
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