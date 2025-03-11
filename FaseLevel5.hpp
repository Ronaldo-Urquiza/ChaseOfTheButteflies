#ifndef FASELEVEL5_HPP
#define FASELEVEL5_HPP

#include "ASCII_Engine/Fase.hpp"
#include "ASCII_Engine/TextContainer.hpp"
#include <string>
#include <list>

class FaseLevel5 : public Fase
{
public:

	FaseLevel5(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	FaseLevel5(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~FaseLevel5() {}

	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);

private:

	ObjetoDeJogo *hero;
	ObjetoDeJogo *Char4;
	ObjetoDeJogo *tapeteC4;
};

#endif 
