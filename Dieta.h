/*
Proyecto aplicacion de dieta
Kirill Makienko Tkachenko
08/06/2023
*/

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cstdlib>

#include "Frutas.h"
#include "Verdura.h"
#include "Granos.h"
#include "Lacteos.h"
#include "Proteina.h"
#include "Ingrediente.h"

#pragma once

// Incluye todos los ingredientes, ccalcula cuantas caloriras le corresponde a cada clase ingrediente con los porcentajes de abajo y selecciona ingredientes random y modifica el gramaje para que se adecue a lo establecido,
// Despues de eso regresa el vector de ingredientes, en main mando a llamar calcular calorias y lo guardo en dieta del usuario

// Lo mismo aplica para dienta con carbohidratos y dieta con grasa

#pragma once

class Dieta
{
    int calorias = 500;
    std::vector<Ingrediente *> ingredientes;

    int perFrutas = 5;
    int perVerduras = 10;
    int perGranos = 10;
    int perLacteos = 10;
    int perProteina = 65;
    int caloriasFrutas, caloriasVerduras, caloriasGranos, caloriasLacteos, caloriasProteina;

    std::vector<Frutas> frutas;
    std::vector<Verdura> verduras;
    std::vector<Granos> granos;
    std::vector<Lacteos> lacteos;
    std::vector<Proteina> proteinas;

public:
    Dieta() {}

    Dieta(int calorias)
    {
        this->calorias = calorias;
    }

    void calcularCaloriasDieta()
    {
        caloriasFrutas = calorias * perFrutas / 100;
        caloriasVerduras = calorias * perVerduras / 100;
        caloriasGranos = calorias * perGranos / 100;
        caloriasLacteos = calorias * perLacteos / 100;
        caloriasProteina = calorias * perProteina / 100;
    }

    void calcularDieta(std::vector<Frutas> frutas, std::vector<Verdura> verduras, std::vector<Granos> granos, std::vector<Lacteos> lacteos, std::vector<Proteina> proteinas)
    {
        int numProt = getRandNum(0, proteinas.size());
        int numLac = getRandNum(0, lacteos.size());
        int numGran = getRandNum(0, granos.size());
        int numVer = getRandNum(0, verduras.size());
        int numFru = getRandNum(0, frutas.size());

        std::cout << caloriasFrutas << " " << caloriasVerduras << " " << caloriasGranos << " " << caloriasLacteos << " " << caloriasProteina << std::endl;

        ingredientes.push_back(&proteinas[numProt]);
        std::cout << *ingredientes[0] << " Proteina" << std::endl;
        ingredientes[0]->setGramaje((caloriasProteina * 100) / ingredientes[0]->getCalorias());
        ingredientes[0]->setCalorias(ingredientes[0]->getGramaje() * ingredientes[0]->getCalorias() / 100);
        ingredientes[0]->setCarbohidratos(ingredientes[0]->getGramaje() * ingredientes[0]->getCarbohidratos() / 100);
        ingredientes[0]->setGrasas(ingredientes[0]->getGramaje() * ingredientes[0]->getGrasas() / 100);

        ingredientes.push_back(&lacteos[numLac]);
        std::cout << *ingredientes[1] << " Lacteos" << std::endl;
        ingredientes[1]->setGramaje((caloriasLacteos * 100) / ingredientes[1]->getCalorias());
        ingredientes[1]->setCalorias(ingredientes[1]->getGramaje() * ingredientes[1]->getCalorias() / 100);
        ingredientes[1]->setCarbohidratos(ingredientes[1]->getGramaje() * ingredientes[1]->getCarbohidratos() / 100);
        ingredientes[1]->setGrasas(ingredientes[1]->getGramaje() * ingredientes[1]->getGrasas() / 100);

        ingredientes.push_back(&granos[numGran]);
        std::cout << *ingredientes[2] << " Granos" << std::endl;
        ingredientes[2]->setGramaje((caloriasGranos * 100) / ingredientes[2]->getCalorias());
        ingredientes[2]->setCalorias(ingredientes[2]->getGramaje() * ingredientes[2]->getCalorias() / 100);
        ingredientes[2]->setCarbohidratos(ingredientes[2]->getGramaje() * ingredientes[2]->getCarbohidratos() / 100);
        ingredientes[2]->setGrasas(ingredientes[2]->getGramaje() * ingredientes[2]->getGrasas() / 100);

        ingredientes.push_back(&verduras[numVer]);
        std::cout << *ingredientes[3] << " Verduras" << std::endl;
        ingredientes[3]->setGramaje((caloriasVerduras * 100) / ingredientes[3]->getCalorias());
        ingredientes[3]->setCalorias(ingredientes[3]->getGramaje() * ingredientes[3]->getCalorias() / 100);
        ingredientes[3]->setCarbohidratos(ingredientes[3]->getGramaje() * ingredientes[3]->getCarbohidratos() / 100);
        ingredientes[3]->setGrasas(ingredientes[3]->getGramaje() * ingredientes[3]->getGrasas() / 100);

        ingredientes.push_back(&frutas[numFru]);
        std::cout << *ingredientes[4] << " Frutas" << std::endl;
        ingredientes[4]->setGramaje((caloriasFrutas * 100) / ingredientes[4]->getCalorias());
        ingredientes[4]->setCalorias(ingredientes[4]->getGramaje() * ingredientes[4]->getCalorias() / 100);
        ingredientes[4]->setCarbohidratos(ingredientes[4]->getGramaje() * ingredientes[4]->getCarbohidratos() / 100);
        ingredientes[4]->setGrasas(ingredientes[4]->getGramaje() * ingredientes[4]->getGrasas() / 100);

        std::cout << " ------------------------ " << std::endl;

        std::cout << *ingredientes[0] << std::endl;
        std::cout << *ingredientes[1] << std::endl;
        std::cout << *ingredientes[2] << std::endl;
        std::cout << *ingredientes[3] << std::endl;
        std::cout << *ingredientes[4] << std::endl;
    }

    int getRandNum(const int &min, const int &max)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(min, max);
        int num = dist(gen);
        return num;
    }

    // Getters and setters, thihs should be used sparingly, the only one that I see real use is the return of ingredients, nevertheless I wrote them just for good practice and just in case someone needs it
    int getCalorias() { return calorias; }
    void setCalorias(int calorias) { this->calorias = calorias; }
    vector<Ingrediente *> getIngredientes() { return ingredientes; }
    void setIngredientes(vector<Ingrediente *> ingredientes) { this->ingredientes = ingredientes; }
    int getPerFrutas() { return perFrutas; }
    void setPerFrutas(int perFrutas) { this->perFrutas = perFrutas; }
    int getPerVerduras() { return perVerduras; }
    void setPerVerduras(int perVerduras) { this->perVerduras = perVerduras; }
    int getPerGranos() { return perGranos; }
    void setPerGranos(int perGranos) { this->perGranos = perGranos; }
    int getPerLacteos() { return perLacteos; }
    void setPerLacteos(int perLacteos) { this->perLacteos = perLacteos; }
    int getPerProteina() { return perProteina; }
    void setPerProteina(int perProteina) { this->perProteina = perProteina; }
    int getCaloriasFrutas() { return caloriasFrutas; }
    void setCaloriasFrutas(int caloriasFrutas) { this->caloriasFrutas = caloriasFrutas; }
    int getCaloriasVerduras() { return caloriasVerduras; }
    void setCaloriasVerduras(int caloriasVerduras) { this->caloriasVerduras = caloriasVerduras; }
    int getCaloriasGranos() { return caloriasGranos; }
    void setCaloriasGranos(int caloriasGranos) { this->caloriasGranos = caloriasGranos; }
    int getCaloriasLacteos() { return caloriasLacteos; }
    void setCaloriasLacteos(int caloriasLacteos) { this->caloriasLacteos = caloriasLacteos; }
    int getCaloriasProteina() { return caloriasProteina; }
    void setCaloriasProteina(int caloriasProteina) { this->caloriasProteina = caloriasProteina; }
    vector<Frutas> getFrutas() { return frutas; }
    void setFrutas(vector<Frutas> frutas) { this->frutas = frutas; }
    vector<Verdura> getVerduras() { return verduras; }
    void setVerduras(vector<Verdura> verduras) { this->verduras = verduras; }
    vector<Granos> getGranos() { return granos; }
    void setGranos(vector<Granos> granos) { this->granos = granos; }
    vector<Lacteos> getLacteos() { return lacteos; }
    void setLacteos(vector<Lacteos> lacteos) { this->lacteos = lacteos; }
    vector<Proteina> getProteinas() { return proteinas; }
    void setProteinas(vector<Proteina> proteinas) { this->proteinas = proteinas; }
};