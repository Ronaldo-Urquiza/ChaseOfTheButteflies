#include "FaseLevel3.hpp"
#include <thread>  // Adiciona essa linha no topo do arquivo
#include <chrono>  // Para definir a duração do sleep
#include "ASCII_Engine/TextBox.hpp"

#include <iostream>

void FaseLevel3::init()
{	
	//Objetos de jogo
	hero = new ObjetoDeJogo("Hero",SpriteAnimado("rsc/heroWalkingLeft.anm",1),37,127);
	objs.push_back(hero);
	
	Char1 = new ObjetoDeJogo("Char1",SpriteAnimado("rsc/Char1F3.anm",1),20,50);
	objs.push_back(Char1);
	
	Char2 = new ObjetoDeJogo("Char2",SpriteAnimado("rsc/Char2F3.anm",2),20,10);
	objs.push_back(Char2);
	
	Char3 = new ObjetoDeJogo("Char3",SpriteAnimado("rsc/Char3F3.anm",2),5,140);
	objs.push_back(Char3);
	
	Char4 = new ObjetoDeJogo("Char4",SpriteAnimado("rsc/Char4F3.anm",1),47,80);
	objs.push_back(Char4);

	tapeteC1 = new ObjetoDeJogo("tapeteC1",SpriteBuffer(1,1),30,60);
	objs.push_back(tapeteC1);
	
	tapeteC2 = new ObjetoDeJogo("tapeteC2",SpriteBuffer(1,2),30,22);
	objs.push_back(tapeteC2);
	
	tapeteC3 = new ObjetoDeJogo("tapeteC3",SpriteBuffer(1,2),15,145);
	objs.push_back(tapeteC3);
		
	tapeteC4 = new ObjetoDeJogo("tapeteC4",SpriteBuffer(2,5),45,100);
	objs.push_back(tapeteC4);
	
	tapeteEscada = new ObjetoDeJogo("tapeteEscada",SpriteBuffer(2,5),56,167);
	objs.push_back(tapeteEscada);
}

unsigned FaseLevel3::run(SpriteBuffer &screen)
{
	std::string ent;
	//padrão
	draw(screen);
	system("clear");
	show(screen);
	
	int teste = 0;
	
	int colidiuCoelho = 0;
	int colidiuCoruja = 0;
	int colidiuGato = 0;
	int colidiuCastor = 0;
	
	int interagir = 0;
	
	while (true)
	{
		
		//lendo entrada
		getline(std::cin,ent);
		
		TextBox caixaTexto(50, 3); // Largura 30, Altura 3
		
		//processando entradas
		int posL = hero->getPosL(), posC = hero->getPosC();
		
		if (hero->colideCom(*tapeteC4) && colidiuCoelho == 0){
			caixaTexto.setText("Coelho");
			caixaTexto.show();
			colidiuCoelho++;
			interagir++;
		}
		else if(hero->colideCom(*tapeteC1) && colidiuCastor == 0){
			caixaTexto.setText("Castor");
			caixaTexto.show();
			colidiuCastor++;
			interagir++;
		}
		else if(hero->colideCom(*tapeteC2) && colidiuGato == 0){
			caixaTexto.setText("Gato");
			caixaTexto.show();
			colidiuGato++;
			interagir++;
		}
		else if(hero->colideCom(*tapeteC3) && colidiuCoruja == 0){
			caixaTexto.setText("Coruja");
			caixaTexto.show();
			colidiuCoruja++;
			interagir++;
		}
		else if(hero->colideCom(*tapeteEscada)){
			caixaTexto.setText("Escada");
			caixaTexto.show();
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