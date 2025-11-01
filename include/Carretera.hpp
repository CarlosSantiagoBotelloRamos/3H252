
#pragma once
#include <vector>
#include "Dibujo.hpp"

class Corral {
public:
    int x, y, ancho, alto;
    Dibujo dibujo_corral;
    std::vector<Dibujo> animales; 

    Corral(int x, int y, int ancho, int alto, ftxui::Color color = ftxui::Color::White)
        : x(x), y(y), ancho(ancho), alto(alto),
          dibujo_corral(x, y, GenerarFiguraCarretera(ancho, alto), color) {}

    static std::vector<std::u32string> GenerarFiguraCarretera(int ancho, int alto) {
        std::vector<std::u32string> figura;

        std::u32string asfalto = std::u32string(ancho, U' '); 
        for (int i = 0; i < alto; ++i) figura.push_back(asfalto);
        return figura;
    }

    void AgregarAnimal(const Dibujo& animal) {
 
        animales.push_back(animal);
    }

    void Dibujar(ftxui::Screen& screen) const {
       
        dibujo_corral.Dibujar(screen);
        for (const auto& animal : animales) {
            animal.Dibujar(screen);
        }
    }
};