#ifndef FASELEVEL3_HPP
#define FASELEVEL3_HPP

#include "ASCII_Engine/Fase.hpp"
#include "ASCII_Engine/TextContainer.hpp"
#include <string>
#include <list>

class FaseLevel3 : public Fase
{
public:

	FaseLevel3(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	FaseLevel3(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~FaseLevel3() {}

	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);

private:

	ObjetoDeJogo *hero;
	
	ObjetoDeJogo *Char1;
	ObjetoDeJogo *Char2;
	ObjetoDeJogo *Char3;
	ObjetoDeJogo *Char4;
	
	ObjetoDeJogo *tapeteC1;
	ObjetoDeJogo *tapeteC2;
	ObjetoDeJogo *tapeteC3;
	ObjetoDeJogo *tapeteC4;
	ObjetoDeJogo *tapeteEscada;
	

};

#endif 
