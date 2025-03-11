#ifndef FIM_HPP
#define FIM_HPP

#include "ASCII_Engine/Fase.hpp"
#include "ASCII_Engine/TextContainer.hpp"
#include <string>
#include <list>

class Fim : public Fase
{
public:

	Fim(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	Fim(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~Fim() {}

	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);

private:

};

#endif 
