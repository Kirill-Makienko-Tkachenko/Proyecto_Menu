/*
Proyecto aplicacion de dieta
Kirill Makienko Tkachenko
08/06/2023
*/

#include <iostream>
#include <string>
#include <vector>
#include "Ingrediente.h"

using namespace std;

//Written with help of ChatGTP

class CalcularCalorias {
private:
    vector<Ingrediente*> ingredientes; //Using polymorphism to manipulate a vector of ingredientes which contains Lacteos, Verdura, Frutas and Granos

public:
    // Add an ingredient to the list
    void agregarIngrediente(Ingrediente* ingrediente) {
        ingredientes.push_back(ingrediente);
    }

    // Calculate the total calories
    const int& calcularTotalCalorias() {
        int totalCalorias = 0;
        for (const auto& ingrediente : ingredientes) { //Const auto& <data type (Ingrediente)> : vector ingredientes
            totalCalorias += ingrediente->getCalorias();
        }
        return totalCalorias;
    }

    // Calculate the total carbohydrates
    const int& calcularTotalCarbohidratos() {
        int totalCarbohidratos = 0;
        for (const auto& ingrediente : ingredientes) {
            totalCarbohidratos += ingrediente->getCarbohidratos();
        }
        return totalCarbohidratos;
    }

    // Calculate the total fats
    const int& calcularTotalGrasas() {
        int totalGrasas = 0;
        for (const auto& ingrediente : ingredientes) {
            totalGrasas += ingrediente->getGrasas();
        }
        return totalGrasas;
    }

    // Print the total nutrition information
    void imprimirTotalNutricion() {
        std::cout << "Total de calorías: " << calcularTotalCalorias() << std::endl;
        std::cout << "Total de carbohidratos: " << calcularTotalCarbohidratos() << std::endl;
        std::cout << "Total de grasas: " << calcularTotalGrasas() << std::endl;
    }
};

ostream& operator<<(ostream& os, CalcularCalorias& c) {
        os << "Total de calorías: " << c.calcularTotalCalorias() << "Total de carbohidratos: " << c.calcularTotalCarbohidratos() << "Total de grasas: " << c.calcularTotalGrasas() << endl;
        return os;
    }