#include "FaseLevel1.hpp"
#include <thread>  // Adiciona essa linha no topo do arquivo
#include <chrono>  // Para definir a duração do sleep
#include "ASCII_Engine/TextBox.hpp"

#include <iostream>

void FaseLevel1::init()
{	
	//Objetos de jogo
	hero = new ObjetoDeJogo("Hero",SpriteAnimado("rsc/heroWalkingLeft.anm",1),30,150);
	objs.push_back(hero);
	
	tapeteSapo = new ObjetoDeJogo("TapeteSapo",SpriteBuffer(2,20),32,105);
	objs.push_back(tapeteSapo);
	
	B1 = new ObjetoDeJogo("B1",SpriteAnimado("rsc/B1.anm",1),20,95);
	objs.push_back(B1);
	
	B2 = new ObjetoDeJogo("B2",SpriteAnimado("rsc/B2.anm",1),19,160);
	objs.push_back(B2);
	
	B3 = new ObjetoDeJogo("B3",SpriteAnimado("rsc/B3.anm",1),10,115);
	objs.push_back(B3);
	
	B4 = new ObjetoDeJogo("B4",SpriteAnimado("rsc/B4.anm",1),2,210);
	objs.push_back(B4);
	
	B5 = new ObjetoDeJogo("B5",SpriteAnimado("rsc/B5.anm",1),18,10);
	objs.push_back(B5);
	
}

unsigned FaseLevel1::run(SpriteBuffer &screen)
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
		
		//checando sapo
		if (hero->colideCom(*tapeteSapo)){
			caixaTexto.setText("Olá coisa de 2 pernas, há tempo não vemos algo como você aqui em Yvy Maraê'y!");
			caixaTexto.show();
			
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("Me chamo Grande Jyi, sou o guardião do rio Yguasu");
			caixaTexto.show();
			
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("Infelizmente, para passar esse rio você precisa de um feitiço, mas eu não estou muito afim de fazê-lo para você de graça.");
			caixaTexto.show();
			
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("Entretanto, se você me disser quantas borboletas você viu por aqui eu faço você chegar até a cidade!");
			caixaTexto.show();
			
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			while(1){
				std::string respostaJogador;
				std::cout << "Quantas borboletas você viu por aqui?" << std::endl;
				std::getline(std::cin, respostaJogador); // Captura toda a entrada

				// Convertendo tudo para minúsculas para evitar erro de capitalização
				for (auto &c : respostaJogador) c = tolower(c);
				
				// Verificando respostas possíveis
				if (respostaJogador == "5" || respostaJogador == "cinco") {
					caixaTexto.setText("Muito bem! Você é observador! Agora, veja o poder do meu feitiço...");
					caixaTexto.show();

					update();
					draw(screen);
					system("clear");
					show(screen);
					screen.clear();

					return Fase::LEVEL_COMPLETE; // O jogador atravessa o rio!
				} 
				
				else {
					update();
					draw(screen);
					system("clear");
					show(screen);
					screen.clear();
					
					caixaTexto.setText("Hmm... Tem certeza? Olhe de novo e tente contar direito.");
					caixaTexto.show();

					update();
					draw(screen);
					system("clear");
					show(screen);
					screen.clear();
				}
			}	
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