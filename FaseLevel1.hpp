#ifndef FASELEVEL1_HPP
#define FASELEVEL1_HPP

#include "ASCII_Engine/Fase.hpp"
#include "ASCII_Engine/TextContainer.hpp"
#include <string>
#include <list>

class FaseLevel1 : public Fase
{
public:
	FaseLevel1(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	FaseLevel1(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~FaseLevel1() {}
	
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);
	
private:

	ObjetoDeJogo *hero;
	ObjetoDeJogo *tapeteSapo;
	ObjetoDeJogo *B1;
	ObjetoDeJogo *B2;
	ObjetoDeJogo *B3;
	ObjetoDeJogo *B4;
	ObjetoDeJogo *B5;

};

#endif 
