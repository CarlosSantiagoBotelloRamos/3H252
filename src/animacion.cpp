#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <Dibujo.hpp>
#include <GestorDibujos.hpp>
#include <Carretera.hpp> 
using namespace ftxui;

// Definición de diferentes coches ASCII
const std::vector<std::u32string> coche_sedan = {
    U"  ____ ",
    U" /_||_\\",
    U"|O----O| "
};

const std::vector<std::u32string> coche_camioneta = {
    U" __________________",
    U"|D|[_][_][_][_][_]\\",
    U"`-O---------------O'"
};

const std::vector<std::u32string> coche_deportivo = {
    U" _    ___",
    U" ,\\__/_|_\\__ ",
    U" (O__________O)"
};

const std::vector<std::u32string> arbol_simple = {
    U"  ^ ",
    U" /_\\",
    U"  | "
};


int main()
{
    // Crear la ventana
    auto screen = Screen::Create(
        Dimension::Fixed(100), // Ancho 
        Dimension::Fixed(24)); // Alto

    
    Corral carretera(1, 8, 98, 12, ftxui::Color::DarkSlateGray3); 

    GestorDibujos gestor;

    // Línea divisoria central (carril superior)
    gestor.Agregar(Dibujo(0, 14, {U"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ----------------------"}, ftxui::Color::Yellow));

    // Línea del borde superior
    gestor.Agregar(Dibujo(0, 7, {U"===================================================================================================="}, ftxui::Color::White));
    // Línea del borde inferior
    gestor.Agregar(Dibujo(0, 21, {U"===================================================================================================="}, ftxui::Color::White));

   
    

    gestor.Agregar(Dibujo(10, 9, coche_sedan, ftxui::Color::Blue)); 

    gestor.Agregar(Dibujo(50, 16, coche_camioneta, ftxui::Color::Red)); 
    
    gestor.Agregar(Dibujo(80, 11, coche_deportivo, ftxui::Color::Green)); 
 
    gestor.Agregar(Dibujo(5, 18, coche_sedan, ftxui::Color::Yellow)); 

    
    gestor.Agregar(Dibujo(1, 5, arbol_simple, ftxui::Color::Green));
    gestor.Agregar(Dibujo(30, 5, arbol_simple, ftxui::Color::Green));
    gestor.Agregar(Dibujo(60, 5, arbol_simple, ftxui::Color::Green));

    
    const int indice_sedan_1 = 3;
    const int indice_camioneta_1 = 4;
    const int indice_deportivo_1 = 5;
    const int indice_sedan_2 = 6;


    int frames = 200; 
    for (int frame = 0; frame < frames; ++frame)
    {
        // Limpia la pantalla
        screen.Clear();

        // **ANIMACIÓN: Mover los coches horizontalmente**
        
        // Coche 1 (Sedán Azul) - Carril Superior (y=9)
        // Se mueve lentamente de izquierda a derecha y se reinicia al llegar al borde.
        int x_sedan_1 = 10 + (frame * 1) % (screen.dimx() + 10);
        if (x_sedan_1 > screen.dimx()) x_sedan_1 -= (screen.dimx() + 10);
        gestor.dibujos[indice_sedan_1].x = x_sedan_1;

        // Coche 2 (Camioneta Roja) - Carril Inferior (y=16)
        // Se mueve de izquierda a derecha.
        int x_camioneta_1 = 50 + (frame * 1) % (screen.dimx() + 10);
        if (x_camioneta_1 > screen.dimx()) x_camioneta_1 -= (screen.dimx() + 10);
        gestor.dibujos[indice_camioneta_1].x = x_camioneta_1;

        // Coche 3 (Deportivo Verde) - Carril Superior (y=11)
        // Se mueve rápido de izquierda a derecha.
        int x_deportivo_1 = 80 + (frame * 2) % (screen.dimx() + 15);
        if (x_deportivo_1 > screen.dimx()) x_deportivo_1 -= (screen.dimx() + 15);
        gestor.dibujos[indice_deportivo_1].x = x_deportivo_1;

        // Coche 4 (Sedán Amarillo) - Carril Inferior (y=18)
        // Se mueve lentamente de derecha a izquierda.
        int x_sedan_2 = 80 - (frame * 1) % (screen.dimx() + 10);
        if (x_sedan_2 < -10) x_sedan_2 += (screen.dimx() + 10);
        gestor.dibujos[indice_sedan_2].x = x_sedan_2;


        
        carretera.Dibujar(screen); 
       
        gestor.DibujarTodos(screen);

        std::cout << screen.ToString();
        std::cout << screen.ResetPosition();
        std::cout << std::flush;

        
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 0;
}