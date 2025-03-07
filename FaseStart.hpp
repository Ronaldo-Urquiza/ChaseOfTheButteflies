#ifndef FASESTART_HPP
#define FASESTART_HPP

#include "ASCII_Engine/Fase.hpp"
#include <string>
#include <list>

class FaseStart : public Fase
{
public:
	FaseStart(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	FaseStart(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~FaseStart() {}
	
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);
	
private:

	ObjetoDeJogo *hero;
	ObjetoDeJogo *tapetePortal;

};

#endif 
