#ifndef FASELEVEL6_HPP
#define FASELEVEL6_HPP

#include "ASCII_Engine/Fase.hpp"
#include "ASCII_Engine/TextContainer.hpp"
#include <string>
#include <list>

class FaseLevel6 : public Fase
{
public:

	FaseLevel6(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	FaseLevel6(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~FaseLevel6() {}

	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);

private:

	ObjetoDeJogo *hero;
	ObjetoDeJogo *tapeteFase;

};

#endif 
