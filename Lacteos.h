/*
Proyecto aplicacion de dieta
Kirill Makienko Tkachenko
08/06/2023
*/

#include <iostream>
#include <string>
#include "Ingrediente.h"

#pragma once

//Written with help of ChatGTP

class Lacteos : public Ingrediente {
private:
    int grasasSaturadas;
    int proteinas;
    int colesterol;

public:
    // Default constructor
    Lacteos() {}

    // Parameterized constructor
    Lacteos(std::string nombre, std::string tipoIngrediente, int calorias, int carbohidratos, int grasas, int gramos,
            int grasasSaturadas, int proteinas, int colesterol)
        : Ingrediente(nombre, tipoIngrediente, calorias, carbohidratos, grasas, gramos),
          grasasSaturadas(grasasSaturadas), proteinas(proteinas), colesterol(colesterol) {}

    // Setters and Getters
    void setGrasasSaturadas(int grasasSaturadas) { this->grasasSaturadas = grasasSaturadas; }
    const int& getGrasasSaturadas() const { return grasasSaturadas; }

    void setProteinas(int proteinas) { this->proteinas = proteinas; }
    const int& getProteinas() { return proteinas; }

    void setColesterol(int colesterol) { this->colesterol = colesterol; }
    const int& getColesterol() { return colesterol; }

    // Method to print dairy details
    void printDairy() {
        std::cout << "Nombre: " << getNombre() << std::endl;
        std::cout << "Tipo de Ingrediente: " << getTipoIngrediente() << std::endl;
        std::cout << "Calorías: " << getCalorias() << std::endl;
        std::cout << "Carbohidratos: " << getCarbohidratos() << std::endl;
        std::cout << "Grasas: " << getGrasas() << std::endl;
        std::cout << "Grasas Saturadas: " << grasasSaturadas << std::endl;
        std::cout << "Proteínas: " << proteinas << std::endl;
        std::cout << "Colesterol: " << colesterol << std::endl;
    }
};

//Overload << operator

std::ostream& operator<<(std::ostream& os, Lacteos& lacteo) {
    os << "Nombre: " << lacteo.getNombre() <<  " Tipo de Ingrediente: " << lacteo.getTipoIngrediente() << " Calorías: " << lacteo.getCalorias() << " Carbohidratos: " << lacteo.getCarbohidratos() << " Grasas: " << lacteo.getGrasas() << std::endl;
    os << " Grasas Saturadas: " << lacteo.getGrasasSaturadas() << " Proteínas: " << lacteo.getProteinas() << " Colesterol: " << lacteo.getColesterol();
    return os;
}
