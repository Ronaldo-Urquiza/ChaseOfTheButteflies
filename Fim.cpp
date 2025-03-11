#include "Fim.hpp"
#include <thread>  // Adiciona essa linha no topo do arquivo
#include <chrono>  // Para definir a duração do sleep
#include "ASCII_Engine/TextBox.hpp"

#include <iostream>

void Fim::init()
{	

}

unsigned Fim::run(SpriteBuffer &screen)
{
	std::string ent;
	//padrão
	draw(screen);
	system("clear");
	show(screen);
	
	int teste = 0;
	
	while (true)
	{
		
		TextBox caixaTexto(50, 3); // Largura 30, Altura 3
		
		caixaTexto.setText("Esqueceu que sou sua neuropsicóloga? *risos* Mas partindo para o seu diagnóstico e no que você trouxe...");
		caixaTexto.show();
		
		update();
		draw(screen);
		system("clear");
		show(screen);
		screen.clear();
		
		caixaTexto.setText("Posso fechar um diagnóstico de autismo!");
		caixaTexto.show();
		
		update();
		draw(screen);
		system("clear");
		show(screen);
		screen.clear();
		
		caixaTexto.setText("Mas não se preocupe! Você terá uma vida tranquila, vamos discutir as melhores formas de você lidar com isso?");
		caixaTexto.show();
		
		update();
		draw(screen);
		system("clear");
		show(screen);
		screen.clear();
		
		system("clear");
		show(screen);
		screen.clear();
		
		caixaTexto.setText("Ah sim.... Eu estava numa consulta médica... Me lembro agora.");
		caixaTexto.show();
		
		system("clear");
		show(screen);
		screen.clear();
		
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		
		return Fase::END_GAME; 
	}
	
	return Fase::END_GAME;
}