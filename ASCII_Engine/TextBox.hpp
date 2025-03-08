#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include <string>
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>
#include "TextSprite.hpp"

class TextBox {
public:
    TextBox(unsigned largura, unsigned altura);
    void setText(const std::string& text);
    void show(); // Exibe a caixa de texto com efeito de digitação

private:
    std::vector<std::string> quebraLinhas(const std::string& text);
    void efeitoDigitacao(const std::string& linha, unsigned deslocamento); // Adicionado o segundo parâmetro de deslocamento
    
    unsigned largura, altura;
    std::vector<std::string> linhas;
};

#endif // TEXTBOX_HPP
