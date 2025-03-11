#include "FaseFinal.hpp"
#include <thread>  // Adiciona essa linha no topo do arquivo
#include <chrono>  // Para definir a duração do sleep
#include "ASCII_Engine/TextBox.hpp"

#include <iostream>

void FaseFinal::init()
{	
	//Objetos de jogo
	hero = new ObjetoDeJogo("Hero",SpriteAnimado("rsc/heroWalkingBack.anm",1),40,136);
	objs.push_back(hero);
	
	tapeteFase = new ObjetoDeJogo("tapeteFase",SpriteBuffer(5,2),19,149);
	objs.push_back(tapeteFase);
	
}

unsigned FaseFinal::run(SpriteBuffer &screen)
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
		
		if (hero->colideCom(*tapeteFase)){
			
			caixaTexto.setText("Olá querido humano... Sou a borboleta rainha daqui... vejo que você possui alguma das minhas súditas contigo...");
			caixaTexto.show();
			
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("A borboleta da percepção.. A borboleta da interação.. A borboleta do descanso.. A borboleta do sentir..");
			caixaTexto.show();
			
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("Obrigada por trazê-las de volta....");
			caixaTexto.show();
	
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("*Você devolve as borboletas *ruídos* -exames- para a rainha borboleta*");
			caixaTexto.show();
			
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("E então...?");
			caixaTexto.show();
			
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("Essa é nossa oitava sessão *ruídos* -encontro- o que você conseguiu perceber até agora?");
			caixaTexto.show();
	
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("Exames? Sessão? Do que você está falando rainha borboleta???");
			caixaTexto.show();
	
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("Hahaha! Não sabia que hoje eu estava tão linda para você me chamar de Rainha Ron!");
			caixaTexto.show();
	
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("Calma... onde estou mesmo????");
			caixaTexto.show();
	
			system("clear");
			screen.clear();
			show(screen);
			
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			
			system("clear");
			screen.clear();
			show(screen);
			
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			
			system("clear");
			show(screen);
			screen.clear();
			
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