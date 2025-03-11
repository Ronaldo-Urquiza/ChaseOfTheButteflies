#ifndef FASELEVEL7_HPP
#define FASELEVEL7_HPP

#include "ASCII_Engine/Fase.hpp"
#include "ASCII_Engine/TextContainer.hpp"
#include <string>
#include <list>

class FaseLevel7 : public Fase
{
public:

	FaseLevel7(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	FaseLevel7(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~FaseLevel7() {}

	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);

private:

	ObjetoDeJogo *hero;
	ObjetoDeJogo *Char1F7;
	ObjetoDeJogo *TapeteChar1F7;
	ObjetoDeJogo *TapeteFase;

};

#endif 
