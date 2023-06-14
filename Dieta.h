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



//Incluye todos los ingredientes, ccalcula cuantas caloriras le corresponde a cada clase ingrediente con los porcentajes de abajo y selecciona ingredientes random y modifica el gramaje para que se adecue a lo establecido,
//Despues de eso regresa el vector de ingredientes, en main mando a llamar calcular calorias y lo guardo en dieta del usuario

//Lo mismo aplica para dienta con carbohidratos y dieta con grasa

#pragma once

class Dieta {

    int calorias = 500;
    vector<Ingrediente*> ingredientes; //We are going to use this vector to store the ingredients that we are going to use in the diet

    //Percentages

int perFrutas = 5;
int perVerduras = 10;
int perGranos = 10;
int perLacteos = 10;
int perProteina = 65;
int caloriasFrutas, caloriasVerduras, caloriasGranos, caloriasLacteos, caloriasProteina;

//Vector of all ingredients
vector<Frutas> frutas;
vector<Verdura> verduras;
vector<Granos> granos;
vector<Lacteos> lacteos;
vector<Proteina> proteinas;






public:

    // Default constructor
    Dieta() {}

    //Constructor
    Dieta(int calorias, vector<Frutas> frutas, vector<Verdura> verduras, vector<Granos> granos, vector<Lacteos> lacteos, vector<Proteina> proteinas) {
        this->calorias = calorias;
        //Assign all the ingredients to the vectors
        this->frutas = frutas;
        this->verduras = verduras;
        this->granos = granos;
        this->lacteos = lacteos;
        this->proteinas = proteinas;

    }

    




    //calculate what calores correspond to each ingredient
    void calcularCaloriasDieta() {
        caloriasFrutas = calorias * perFrutas / 100;
        caloriasVerduras = calorias * perVerduras / 100;
        caloriasGranos = calorias * perGranos / 100;
        caloriasLacteos = calorias * perLacteos / 100;
        caloriasProteina = calorias * perProteina / 100;
    }

    void calcularDieta(vector<Frutas> frutas, vector<Verdura> verduras, vector<Granos> granos, vector<Lacteos> lacteos, vector<Proteina> proteinas, vector<Ingrediente*> ingredientes) {

        random_device rd; //get random number from device
        mt19937 gen(rd()); //set seed for RNG
        uniform_int_distribution<int> dist(0,proteinas.size());
        int num = dist(gen);
        ingredientes.push_back(&proteinas[num]);
    }
    

};