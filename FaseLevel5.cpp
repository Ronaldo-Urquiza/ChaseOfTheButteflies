#include "FaseLevel5.hpp"
#include <thread>  // Adiciona essa linha no topo do arquivo
#include <chrono>  // Para definir a duração do sleep
#include "ASCII_Engine/TextBox.hpp"

#include <iostream>

void FaseLevel5::init()
{	
	//Objetos de jogo
	hero = new ObjetoDeJogo("Hero",SpriteAnimado("rsc/heroWalkingLeft.anm",1),37,127);
	objs.push_back(hero);
	
	Char4 = new ObjetoDeJogo("Char4",SpriteAnimado("rsc/Char4F3.anm",1),47,80);
	objs.push_back(Char4);
	
	tapeteC4 = new ObjetoDeJogo("tapeteC4",SpriteBuffer(2,5),45,100);
	objs.push_back(tapeteC4);
}

unsigned FaseLevel5::run(SpriteBuffer &screen)
{
	std::string ent;
	//padrão
	draw(screen);
	system("clear");
	show(screen);
	
	int teste = 0;
	int colidiuCoelho = 0;
	
	while (true)
	{
		
		//lendo entrada
		getline(std::cin,ent);
		
		TextBox caixaTexto(50, 3); // Largura 30, Altura 3
		
		//processando entradas
		int posL = hero->getPosL(), posC = hero->getPosC();
		
		if (hero->colideCom(*tapeteC4) && colidiuCoelho == 0){
			caixaTexto.setText("Já vai humano? Espero que tenha gostado da estadia! Boa sorte nas suas próximas perguntas... ou respostas...");
			caixaTexto.show();
				
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("*Você se dirige até a porta do hotel e decide ir embora*");
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