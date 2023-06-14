/*
Proyecto aplicacion de dieta
Kirill Makienko Tkachenko
08/06/2023
*/

#include <iostream>
#include <string>

#pragma once

using namespace std;

class Ingrediente {
private:
    string nombre, tipoIngrediente;
    int calorias, carbohidratos, grasas, gramos;

public:
    // Inline constructor
    Ingrediente(string nombre, string tipoIngrediente, int calorias, int carbohidratos, int grasas, int gramos)
        : nombre(nombre), tipoIngrediente(tipoIngrediente), calorias(calorias), carbohidratos(carbohidratos), grasas(grasas), gramos(gramos) {}

    // Default constructor
    Ingrediente() = default;

    // Getters
    const string& getNombre() { return nombre; }
    const string& getTipoIngrediente() { return tipoIngrediente; }
    const int& getCalorias() { return calorias; }
    const int& getCarbohidratos() { return carbohidratos; }
    const int& getGrasas() { return grasas; }

    // Setters
    void setNombre(string nom) { nombre = nom; }
    void setTipoIngrediente(string tipoI) { tipoIngrediente = tipoI; }
    void setCalorias(int cal) { calorias = cal; }
    void setCarbohidratos(int carbohidratos) { this->carbohidratos = carbohidratos; }
    void setGrasas(int grasas) { this->grasas = grasas; }

    void printIngredient() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Tipo de Ingrediente: " << tipoIngrediente << endl;
        cout << "Calorías: " << calorias << endl;
        cout << "Carbohidratos: " << carbohidratos << endl;
        cout << "Grasas: " << grasas << endl;
    }
};

ostream& operator<<(ostream& os, Ingrediente& a) {
    os << "Nombre: " << a.getNombre() << "Tipo de Ingrediente: " << a.getTipoIngrediente() << "Calorías: " << a.getCalorias() << "Carbohidratos: " << a.getCarbohidratos() << "Grasas: " << a.getGrasas() << endl;
    return os;
}
