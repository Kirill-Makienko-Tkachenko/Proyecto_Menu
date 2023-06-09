/*
Proyecto aplicacion de dieta
Kirill Makienko Tkachenko
08/06/2023
*/

#include <iostream>
#include <string>
#include "Ingrediente.h"

using namespace std;

class Fruta : public Ingrediente {
private:
    int azucar;

public:
    // Default constructor
    Fruta() {}

    // Parameterized constructor
    Fruta(string nombre, string tipoIngrediente, int calorias, int carbohidratos, int grasas, int azucar)
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
