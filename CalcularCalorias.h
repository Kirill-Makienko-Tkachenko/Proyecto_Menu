/*
Proyecto aplicacion de dieta
Kirill Makienko Tkachenko
08/06/2023
*/

#include <iostream>
#include <string>
#include <vector>
#include "Ingrediente.h"

#pragma once

using namespace std;

//Written with help of ChatGTP

class CalcularCalorias {
private:
    vector<Ingrediente*> ingredientes;

public:
    void agregarIngrediente(Ingrediente* ingrediente) {
        ingredientes.push_back(ingrediente);
    }

    void agregarIngredientes(const vector<Ingrediente>& ingredientesVector) {
        for (const auto& ingrediente : ingredientesVector) {
            ingredientes.push_back(new Ingrediente(ingrediente));
        }
    }

    int calcularTotalCalorias() const {
        int totalCalorias = 0;
        for (const auto& ingrediente : ingredientes) {
            totalCalorias += ingrediente->getCalorias();
        }
        return totalCalorias;
    }

    int calcularTotalCarbohidratos() const {
        int totalCarbohidratos = 0;
        for (const auto& ingrediente : ingredientes) {
            totalCarbohidratos += ingrediente->getCarbohidratos();
        }
        return totalCarbohidratos;
    }

    int calcularTotalGrasas() const {
        int totalGrasas = 0;
        for (const auto& ingrediente : ingredientes) {
            totalGrasas += ingrediente->getGrasas();
        }
        return totalGrasas;
    }
};


ostream& operator<<(ostream& os, const CalcularCalorias& c) {
    os << "Total de calorías: " << c.calcularTotalCalorias() << ", ";
    os << "Total de carbohidratos: " << c.calcularTotalCarbohidratos() << ", ";
    os << "Total de grasas: " << c.calcularTotalGrasas();
    return os;
}