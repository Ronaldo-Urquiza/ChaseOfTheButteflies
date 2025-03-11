#include "FaseLevel7.hpp"
#include <thread>  // Adiciona essa linha no topo do arquivo
#include <chrono>  // Para definir a duração do sleep
#include "ASCII_Engine/TextBox.hpp"

#include <iostream>

void FaseLevel7::init()
{	
	//Objetos de jogo
	hero = new ObjetoDeJogo("Hero",SpriteAnimado("rsc/heroWalkingLeft.anm",1),20,220);
	objs.push_back(hero);
	
	Char1F7 = new ObjetoDeJogo("Char1F7",SpriteAnimado("rsc/Char1F7.anm",2),32,80);
	objs.push_back(Char1F7);
	
	TapeteChar1F7 = new ObjetoDeJogo("TapeteChar1F7",SpriteBuffer(2,5),35,111);
	objs.push_back(TapeteChar1F7);
	
	TapeteFase = new ObjetoDeJogo("TapeteFase",SpriteBuffer(2,5),32,10);
	objs.push_back(TapeteFase);
}

unsigned FaseLevel7::run(SpriteBuffer &screen)
{
	std::string ent;
	//padrão
	draw(screen);
	system("clear");
	show(screen);
	
	int teste = 0;
	
	int colidiuMorcego = 0;
	int interagiuMorcego = 0;
	
	while (true)
	{
		//lendo entrada
		getline(std::cin,ent);
		
		TextBox caixaTexto(50, 3); // Largura 30, Altura 3
		
		//processando entradas
		int posL = hero->getPosL(), posC = hero->getPosC();
		
		if (hero->colideCom(*TapeteChar1F7) && colidiuMorcego == 0){
			
			caixaTexto.setText("Tic-tic-tic!...OH! Um HUMANO!!");
			caixaTexto.show();
			
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("Escutei da sua espécie nas lendas antigas, minha vó conheceu o último humano que veio parar aqui!");
			caixaTexto.show();
			
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("É um prazer te conhecer!!! Me chamo Anduí, sou o 875º quinto morcego a cuidar da fazenda de frutas Yva Renda! Seja bem vindo!!!");
			caixaTexto.show();
			
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("Vamos experimentar algumas frutinhas, a colheita acabou de acontecer! Foi fruta pra todo lado!! Toma esse caju aqui!");
			caixaTexto.show();
			
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("Hmmm... estranho. É macio, meio fibroso... mas suculento. E doce? Mas com um toque ácido no final. Meu cérebro não consegue decidir se gosta ou não.");
			caixaTexto.show();
			
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("Ótimo ótimo, experimenta essa maçã agora!");
			caixaTexto.show();
			
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("O barulho ao morder é muito alto… crunch. É gostoso, mas essa crocância me surpreende toda vez. Minha boca sente tudo de uma vez só.");
			caixaTexto.show();
			
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("Suas reações faciais são esquisitas hehe! Que diferente, é como se para você uma mera fruta significasse grandes coisas *risos em morceguês*");
			caixaTexto.show();
			
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("Experimenta esse ROMÃ agora!");
			caixaTexto.show();
			
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("É como mastigar pequenas bolhas d'água que estouram de repente! O suco explode e some rápido... e as sementes? O que eu faço com elas?! AH que azedo!!!");
			caixaTexto.show();
			
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("Vamos experimentar agora essa aqu....");
			caixaTexto.show(); 
			
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("NÃO! CHEGA! Me perdoe caro amigo morceguinho, sua colheita é ótima mas não aguento tantas texturas de uma só vez, preciso continuar minha jornada..");
			caixaTexto.show();
			
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("Oh! Perdão humano! Obrigado por experimentar minhas deliciosas frutinhas, acho que entendo o que você acabou de dizer um pouco, enfim.. Boa jornada então!");
			caixaTexto.show();
			
			colidiuMorcego++;
			interagiuMorcego++;
		}
		
		if (hero->colideCom(*TapeteFase) && interagiuMorcego>0){
			
			caixaTexto.setText("Deve ser por aqui o caminho certo...");
			caixaTexto.show();
			
			update();
			draw(screen);
			system("clear");
			show(screen);
			screen.clear();
			
			caixaTexto.setText("*Você adentra no caminho desconhecido, isso não tem fim?*");
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