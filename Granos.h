/*
Proyecto aplicacion de dieta
Kirill Makienko Tkachenko
08/06/2023
*/

#include <iostream>
#include <string>
#include "Ingrediente.h"

using namespace std;

class Granos : public Ingrediente {
private:
    int proteinas;
    int sodio;
    bool isIntegral;

public:
    // Default constructor
    Granos() {}

    // Parameterized constructor
    Granos(string nombre, string tipoIngrediente, int calorias, int carbohidratos, int grasas,
           int proteinas, int sodio, bool isIntegral)
        : Ingrediente(nombre, tipoIngrediente, calorias, carbohidratos, grasas),
          proteinas(proteinas), sodio(sodio), isIntegral(isIntegral) {}

    //Getters
   
    const int& getProteinas() { return proteinas; }
    const int& getSodio() const { return sodio; }
    const bool& getIsIntegral() const { return isIntegral; }

    //Setter
    void setIsIntegral(bool isIntegral) { this->isIntegral = isIntegral; }
    void setSodio(int sodio) { this->sodio = sodio; }
    void setProteinas(int proteinas) { this->proteinas = proteinas; }

    void printGrain() {
        std::cout << "Nombre: " << getNombre() << std::endl;
        std::cout << "Tipo de Ingrediente: " << getTipoIngrediente() << std::endl;
        std::cout << "Calorías: " << getCalorias() << std::endl;
        std::cout << "Carbohidratos: " << getCarbohidratos() << std::endl;
        std::cout << "Grasas: " << getGrasas() << std::endl;
        std::cout << "Proteínas: " << proteinas << std::endl;
        std::cout << "Sodio: " << sodio << std::endl;
        std::cout << "Es Integral: " << (isIntegral ? "Sí" : "No") << std::endl;
    }
};

//Overload << operator
ostream& operator<<(ostream& os, Granos& grano) {
    os << "Nombre: " << grano.getNombre() << endl;
    os << "Tipo de Ingrediente: " << grano.getTipoIngrediente() << endl;
    os << "Calorías: " << grano.getCalorias() << endl;
    os << "Carbohidratos: " << grano.getCarbohidratos() << endl;
    os << "Grasas: " << grano.getGrasas() << endl;
    os << "Proteínas: " << grano.getProteinas() << endl;
    os << "Sodio: " << grano.getSodio() << endl;
    os << "Es Integral: " << (grano.getIsIntegral() ? "Sí" : "No") << endl;
    return os;
}