
#pragma once
#include <vector>
#include "Dibujo.hpp"

class Corral {
public:
    int x, y, ancho, alto;
    Dibujo dibujo_corral;
    std::vector<Dibujo> animales; // Se mantiene por si se quiere añadir algo en el futuro

    Corral(int x, int y, int ancho, int alto, ftxui::Color color = ftxui::Color::White)
        : x(x), y(y), ancho(ancho), alto(alto),
          dibujo_corral(x, y, GenerarFiguraCarretera(ancho, alto), color) {}

    // Función modificada para generar el fondo de la carretera (asfalto sólido)
    static std::vector<std::u32string> GenerarFiguraCarretera(int ancho, int alto) {
        std::vector<std::u32string> figura;
        // La carretera será un bloque sólido de espacio ' ' que será coloreado por el fondo del píxel
        std::u32string asfalto = std::u32string(ancho, U' '); 
        for (int i = 0; i < alto; ++i) figura.push_back(asfalto);
        return figura;
    }

    void AgregarAnimal(const Dibujo& animal) {
        // La lógica del corral no es relevante para la carretera, pero la mantengo
        // y solo añado el dibujo sin chequear límites de "corral".
        animales.push_back(animal);
    }

    void Dibujar(ftxui::Screen& screen) const {
        // NOTA: Se ha cambiado el nombre de GenerarFiguraCorral a GenerarFiguraCarretera
        // en el constructor, pero esta función `Dibujar` sigue funcionando.
        dibujo_corral.Dibujar(screen);
        for (const auto& animal : animales) {
            animal.Dibujar(screen);
        }
    }
};