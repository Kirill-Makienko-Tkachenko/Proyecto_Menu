/*
Proyecto aplicacion de dieta
Kirill Makienko Tkachenko
08/06/2023
*/

#include <iostream>
#include <string>
#include "Ingrediente.h"

#pragma once

using namespace std;

class Proteina : public Ingrediente {
private:
    int grasasSaturadas;
    int proteinas;
    int colesterol;
    int sodio;

public:
    // Default constructor
    Proteina() {}

    // Parameterized constructor
    Proteina(string nombre, string tipoIngrediente, int calorias, int carbohidratos, int grasas, int gramos,
             int grasasSaturadas, int proteinas, int colesterol, int sodio)
        : Ingrediente(nombre, tipoIngrediente, calorias, carbohidratos, grasas, gramos),
          grasasSaturadas(grasasSaturadas), proteinas(proteinas), colesterol(colesterol), sodio(sodio) {}

    // Setters and Getters
   
    const int& getGrasasSaturadas() { return grasasSaturadas; }
    const int& getSodio() { return sodio; }
    const int& getProteinas() { return proteinas; }
    const int& getColesterol() { return colesterol; }
    
    void setSodio(int& sodio) { this->sodio = sodio; }
    void setGrasasSaturadas(int& grasasSat) { grasasSaturadas = grasasSat; }
    void setProteinas(int& prote) { this->proteinas = prote; }
    void setColesterol(int& QuieresQueTeGuizeUnChicharron) { colesterol = QuieresQueTeGuizeUnChicharron; } //Alto Fito Olivares

    
    // Method to print protein details
    void printProtein() {
        cout << "Nombre: " << getNombre() << endl;
        cout << "Tipo de Ingrediente: " << getTipoIngrediente() << endl;
        cout << "Calorías: " << getCalorias() << endl;
        cout << "Carbohidratos: " << getCarbohidratos() << endl;
        cout << "Grasas: " << getGrasas() << endl;
        cout << "Grasas Saturadas: " << grasasSaturadas << endl;
        cout << "Proteínas: " << proteinas << endl;
        cout << "Colesterol: " << colesterol << endl;
        cout << "Sodio: " << sodio << endl;
    }
};

//Overload << operator

ostream& operator<<(ostream& os, Proteina& proteina) {
    os << "Nombre: " << proteina.getNombre() << "Tipo de Ingrediente: " << proteina.getTipoIngrediente() << "Calorías: " << proteina.getCalorias() << "Carbohidratos: " << proteina.getCarbohidratos() << "Grasas: " << proteina.getGrasas() << endl;
    os << "Grasas Saturadas: " << proteina.getGrasasSaturadas() << "Proteínas: " << proteina.getProteinas() << "Colesterol: " << proteina.getColesterol() << "Sodio: " << proteina.getSodio();
    return os;
}