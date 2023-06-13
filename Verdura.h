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

class Verdura : public Ingrediente {
private:
    int proteinas;
    bool isOrganico;

public:
    // Default constructor
    Verdura() {}

    // Parameterized constructor
    Verdura(std::string nombre, std::string tipoIngrediente, int calorias, int carbohidratos, int grasas,
            int proteinas, bool isOrganico)
        : Ingrediente(nombre, tipoIngrediente, calorias, carbohidratos, grasas),
          proteinas(proteinas), isOrganico(isOrganico) {}

    // Setters and Getters
    void setProteinas(int proteinas) { this->proteinas = proteinas; }
    const int& getProteinas() { return proteinas; }

    void setIsOrganico(bool isOrganico) { this->isOrganico = isOrganico; }
    const bool& getIsOrganico() { return isOrganico; }

    // Method to print vegetable details
    void printVerdura() {
        std::cout << "Nombre: " << getNombre() << std::endl;
        std::cout << "Tipo de Ingrediente: " << getTipoIngrediente() << std::endl;
        std::cout << "Calorías: " << getCalorias() << std::endl;
        std::cout << "Carbohidratos: " << getCarbohidratos() << std::endl;
        std::cout << "Grasas: " << getGrasas() << std::endl;
        std::cout << "Proteínas: " << proteinas << std::endl;
        std::cout << "Es Orgánico: " << (isOrganico ? "Sí" : "No") << std::endl;
    }
};

//Overload << operator

std::ostream& operator<<(std::ostream& os, Verdura& verdura) {
    os << "Nombre: " << verdura.getNombre() << " Tipo de Ingrediente: " << verdura.getTipoIngrediente() << " Calorías: " << verdura.getCalorias() << " Carbohidratos: " << verdura.getCarbohidratos() << std::endl;
    os << "Grasas: " << verdura.getGrasas() << " Proteínas: " << verdura.getProteinas() << " Es Orgánico: " << (verdura.getIsOrganico() ? "Sí" : "No");
    return os;
}
