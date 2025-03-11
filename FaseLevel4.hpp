#ifndef FASELEVEL4_HPP
#define FASELEVEL4_HPP

#include "ASCII_Engine/Fase.hpp"
#include "ASCII_Engine/TextContainer.hpp"
#include <string>
#include <list>

class FaseLevel4 : public Fase
{
public:

	FaseLevel4(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	FaseLevel4(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~FaseLevel4() {}

	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);

private:

	ObjetoDeJogo *hero;
	ObjetoDeJogo *cama;
	ObjetoDeJogo *tapeteCama;
	

};

#endif 
