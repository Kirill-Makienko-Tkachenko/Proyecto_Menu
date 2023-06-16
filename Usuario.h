/*
Proyecto aplicacion de dieta
Kirill Makienko Tkachenko
08/06/2023
*/


//Written with ChatGPT
#include <iostream>
#include <string>
#include <vector>
#include "Ingrediente.h"
#include "CalcularCalorias.h"

#pragma once

class Usuario {
private:
    std::string nombre;
    double peso;
    double altura;
    vector<Ingrediente> ingredientes; //Used to create a vector of ingredients, which will basically be used as the diet, also not a pointer vector because it gives WAY to much trobule
    
public:
    // Default constructor
    Usuario() {}

    // Parameterized constructor wihout ingredients
    Usuario(const std::string& nombre, double peso, double altura)
        : nombre(nombre), peso(peso), altura(altura) {}
        
    Usuario(const std::string& nombre, double peso, double altura, vector<Ingrediente*> ingredientes)
        : nombre(nombre), peso(peso), altura(altura) {}

    // Setter and Getter for nombre
    void setNombre(const std::string& nombre) { this->nombre = nombre; }
    std::string getNombre() const { return nombre; }

    // Setter and Getter for peso
    void setPeso(double peso) { this->peso = peso; }
    double getPeso() const { return peso; }

    // Setter and Getter for altura
    void setAltura(double altura) { this->altura = altura; }
    double getAltura() const { return altura; }

    // Getter for the vector Ingredientes
    const std::vector<Ingrediente> getIngredientes() { return ingredientes; }


    // Calculate BMI
    double calcularBMI() const {
        if (altura <= 0.0) {
            std::cout << "Error: Altura inválida" << std::endl;
            return 0.0;
        }

        double alturaMetros = altura / 100.0;  // Convert altura from cm to meters
        return peso / (alturaMetros * alturaMetros);
    }

    // Print nombre
    void printNombre() const {
        std::cout << "Nombre: " << nombre << std::endl;
    }

    // Add vector Ingredientes that acts as the diet
    void agregarIngredientes(std::vector<Ingrediente*>& nuevosIngredientes) {
        ingredientes.insert(ingredientes.end(), nuevosIngredientes.begin(), nuevosIngredientes.end());
    }


    
    // Overloading the << operator
    friend std::ostream& operator<<(std::ostream& out, const Usuario& usuario) {
        out << "Nombre: " << usuario.nombre << std::endl;
        out << "Peso: " << usuario.peso << std::endl;
        out << "Altura: " << usuario.altura << std::endl;
        return out;
    }
};