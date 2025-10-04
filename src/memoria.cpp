#include <iostream>


using namespace std;

class empleado
{
    private: //nace de la relcion tiene
    char nombre [10]: //10 bytes
    int edad;
    char direction[255] //255 bytes
    int telefono; //4b

    public: interfaz nace de usa
    int leeredad ()
    {return 0;
    
    }



}   //273 bytes
int main(int argc, char const *argv[])
{

    
//enteros
cout << "Tamano de int" <<sizeof(int) << endl;
cout << "Tamano de long" <<sizeof(long) << endl;
//punto flotante 
cout << "Tamano de float" <<sizeof(float) << endl;
cout << "Tamano de double" <<sizeof(double) << endl;

//Bytes
cout << "Tamano de char" <<sizeof(char) << endl;
cout << "Tamano de byte" <<sizeof(byte) << endl;
cout << "Tamano de bool" <<sizeof(bool) << endl;

cout << "Tamano de puntero" <<sizeof(int*) << endl;
//tamano tipos no nativos
empleado empleados[10]; //273 bytes
cout << "Tamano de empleado" <<sizeof(empleado) << endl;
cout << "empleados" <<empleados[0].leeredad() << endl;

int a = 64;
char b = (char) a;
cout << b << endl;
    return 0;
}
