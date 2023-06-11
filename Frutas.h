/*
Proyecto aplicacion de dieta
Kirill Makienko Tkachenko
08/06/2023
*/

#include <iostream>
#include <string>
#include "Ingrediente.h"

using namespace std;

class Frutas : public Ingrediente {
private:
    int azucar;

public:
    // Default constructor
    Frutas() {}

    // Parameterized constructor
    Frutas(string nombre, string tipoIngrediente, int calorias, int carbohidratos, int grasas, int azucar)
        : Ingrediente(nombre, tipoIngrediente, calorias, carbohidratos, grasas), azucar(azucar) {}

    // Setter and Getter for azucar
    void setAzucar(int azucar) { this->azucar = azucar; }
    int getAzucar() const { return azucar; }

    // Method to print fruit details
    void printFruit() {
        cout << "Nombre: " << getNombre() << endl;
        cout << "Tipo de Ingrediente: " << getTipoIngrediente() << endl;
        cout << "Calorías: " << getCalorias() << endl;
        cout << "Carbohidratos: " << getCarbohidratos() << endl;
        cout << "Grasas: " << getGrasas() << endl;
        cout << "Azúcar: " << azucar << endl;
    }
};

//Overload << operator
ostream& operator<<(ostream& os, Frutas& fruta) {
    os << "Nombre: " << fruta.getNombre() << endl;
    os << "Tipo de Ingrediente: " << fruta.getTipoIngrediente() << endl;
    os << "Calorías: " << fruta.getCalorias() << endl;
    os << "Carbohidratos: " << fruta.getCarbohidratos() << endl;
    os << "Grasas: " << fruta.getGrasas() << endl;
    os << "Azúcar: " << fruta.getAzucar() << endl;
    return os;
}

