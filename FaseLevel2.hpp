#ifndef FASELEVEL2_HPP
#define FASELEVEL2_HPP

#include "ASCII_Engine/Fase.hpp"
#include "ASCII_Engine/TextContainer.hpp"
#include <string>
#include <list>

class FaseLevel2 : public Fase
{
public:

	FaseLevel2(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	FaseLevel2(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~FaseLevel2() {}

	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);

private:

	ObjetoDeJogo *hero;
	ObjetoDeJogo *tapeteHotel;

};

#endif 
