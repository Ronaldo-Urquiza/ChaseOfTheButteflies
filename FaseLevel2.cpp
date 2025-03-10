#include "FaseLevel2.hpp"
#include <thread>  // Adiciona essa linha no topo do arquivo
#include <chrono>  // Para definir a duração do sleep
#include "ASCII_Engine/TextBox.hpp"

#include <iostream>

void FaseLevel2::init()
{	
	//Objetos de jogo
	hero = new ObjetoDeJogo("Hero",SpriteAnimado("rsc/heroWalkingLeft.anm",1),35,200);
	objs.push_back(hero);
	
	tapeteHotel = new ObjetoDeJogo("TapeteHotel",SpriteBuffer(1,5),32,71);
	objs.push_back(tapeteHotel);
	
}

unsigned FaseLevel2::run(SpriteBuffer &screen)
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
		
		TextBox caixaTexto(50, 3); // Largura 30, Altura 3
		
		//processando entradas
		int posL = hero->getPosL(), posC = hero->getPosC();
		
		if (hero->colideCom(*tapeteHotel)){
			caixaTexto.setText("A arquitetura desse prédio hotel, não combina com o ambiente ao redor. O vento está batendo contra as janelas de um jeito estranho. O cheiro aqui é diferente.");
			caixaTexto.show();
			
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("Talvez seja para onde eu deva ir...");
			caixaTexto.show();
			
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("*Você bate na porta do hotel...*");
			caixaTexto.show();
			
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("*Alguém abre a porta para você...*");
			caixaTexto.show();
	
			system("clear");
			screen.clear();
			show(screen);
			
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));

			return Fase::LEVEL_COMPLETE; // O jogador atravessa o rio!
		}
		
		if (ent == "w" && hero->getPosL() > 10 && teste == 0)
			hero->moveUp(2);
		else if (ent == "s" && hero->getPosL() < screen.getAltura() - 15 && teste == 0)
			hero->moveDown(2);
		else if (ent == "a" && hero->getPosC() > 12 && teste == 0)
			hero->moveLeft(7);
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