#include "TextBox.hpp"
#include <iostream>
#include <sstream>
#include <codecvt>
#include <locale>
#include <thread>
#include <chrono>

// Construtor
TextBox::TextBox(unsigned largura, unsigned altura) 
    : largura(largura), altura(altura) {}

// Quebra um texto longo em várias linhas para caber na caixa
std::vector<std::string> TextBox::quebraLinhas(const std::string& text) {
    std::vector<std::string> resultado;
    std::string temp = "";
    
    std::istringstream stream(text);
    std::string palavra;

    while (stream >> palavra) {
        if (temp.length() + palavra.length() + 1 > largura) { 
            resultado.push_back(temp); // Adiciona a linha antes de estourar
            temp = palavra; // Inicia nova linha com a palavra atual
        } else {
            if (!temp.empty()) temp += " "; // Adiciona espaço entre palavras
            temp += palavra;
        }
    }
    if (!temp.empty()) resultado.push_back(temp); // Última linha

    return resultado;
}

// Conta corretamente os caracteres visíveis ignorando múltiplos bytes do UTF-8
size_t contarCaracteresVisiveis(const std::string& texto) {
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring wideTexto = converter.from_bytes(texto);
    return wideTexto.size(); // Retorna o número real de caracteres visíveis
}

// Define o texto e divide em linhas formatadas
void TextBox::setText(const std::string& text) {
    linhas = quebraLinhas(text);
}

// Efeito de digitação letra por letra
void TextBox::efeitoDigitacao(const std::string& linha, unsigned deslocamento) {
    std::cout << std::string(deslocamento, ' '); // Espaço antes do texto
    for (char c : linha) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Delay entre caracteres
    }
}

// Renderiza a caixa de texto no meio da tela
void TextBox::show() {
    unsigned largura_da_tela = 250; // Definido pelo usuário
    unsigned deslocamento = (largura_da_tela - largura) / 2; // Centralizar
    
    std::string borda = "+" + std::string(largura + 1, '-') + "+";

    std::cout << std::string(deslocamento, ' ') << borda << std::endl;
    for (const auto& linha : linhas) {
        std::cout << std::string(deslocamento, ' ') << "| ";
        efeitoDigitacao(linha, 0); 
        std::cout << std::string(largura - contarCaracteresVisiveis(linha), ' ') << "|" << std::endl;
    }
    std::cout << std::string(deslocamento, ' ') << borda << std::endl;
    
    std::cout << std::string(deslocamento, ' ') << "Pressione ENTER para continuar..." << std::endl;
    std::cin.ignore();
}
