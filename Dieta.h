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

    void calcularDieta(vector<Frutas> frutas, vector<Verdura> verduras, vector<Granos> granos, vector<Lacteos> lacteos, vector<Proteina> proteinas) {

        //Get all the random numbers for generating the diet
        int numProt = getRandNum(0, proteinas.size());
        int numLac = getRandNum(0, lacteos.size());
        int numGran = getRandNum(0, granos.size());
        int numVer = getRandNum(0, verduras.size());
        int numFru = getRandNum(0, frutas.size());

        cout << caloriasFrutas << " " << caloriasVerduras << " " << caloriasGranos << " " << caloriasLacteos << " " << caloriasProteina << endl;
        
        ingredientes.push_back(&proteinas[numProt]);
        cout << *ingredientes[0] << " Proteina" << endl;
        ingredientes[0]->setGramaje((caloriasProteina * 100 )/ ingredientes[0]->getCalorias());
        ingredientes[0]->setCalorias(ingredientes[0]->getGramaje() * ingredientes[0]->getCalorias() / 100);

        ingredientes.push_back(&lacteos[numLac]);
        cout << *ingredientes[1] << " Lacteos" << endl;
        ingredientes[1]->setGramaje((caloriasLacteos * 100 )/ ingredientes[1]->getCalorias());
        ingredientes[1]->setCalorias(ingredientes[1]->getGramaje() * ingredientes[1]->getCalorias() / 100);

        ingredientes.push_back(&granos[numGran]);
        cout << *ingredientes[2] << " Granos" << endl;
        ingredientes[2]->setGramaje((caloriasGranos * 100 )/ ingredientes[2]->getCalorias());
        ingredientes[2]->setCalorias(ingredientes[2]->getGramaje() * ingredientes[2]->getCalorias() / 100);

        ingredientes.push_back(&verduras[numVer]);
        cout << *ingredientes[3] <<" Verduras" << endl;
        ingredientes[3]->setGramaje((caloriasVerduras * 100 )/ ingredientes[3]->getCalorias());
        ingredientes[3]->setCalorias(ingredientes[3]->getGramaje() * ingredientes[3]->getCalorias() / 100);

        ingredientes.push_back(&frutas[numFru]);
        cout << *ingredientes[4] <<" Frutas" << endl;
        ingredientes[4]->setGramaje((caloriasFrutas * 100 )/ ingredientes[4]->getCalorias());
        ingredientes[4]->setCalorias(ingredientes[4]->getGramaje() * ingredientes[4]->getCalorias() / 100);


        cout << " ------------------------ " << endl;
        //Print the ingredients
        cout << *ingredientes[0] << endl;
        cout << *ingredientes[1] << endl;
        cout << *ingredientes[2] << endl;
        cout << *ingredientes[3] << endl;
        cout << *ingredientes[4] << endl;

        


    }
    

    int getRandNum(const int& min, const int& max) {
        random_device rd; //get random number from device
        mt19937 gen(rd()); //set seed for RNG
        uniform_int_distribution<int> dist(min, max);
        int num = dist(gen);
        return num;
    }

    //Getters and setters, thihs should be used sparingly, the only one that I see real use is the return of ingredients, nevertheless I wrote them just for good practice and just in case someone needs it
    int getCalorias() { return calorias; }
    void setCalorias(int calorias) {this->calorias = calorias;}
    vector<Ingrediente*> getIngredientes() {return ingredientes;}
    void setIngredientes(vector<Ingrediente*> ingredientes) {this->ingredientes = ingredientes;}
    int getPerFrutas() {return perFrutas;}
    void setPerFrutas(int perFrutas) {this->perFrutas = perFrutas;}
    int getPerVerduras() {return perVerduras;}
    void setPerVerduras(int perVerduras) {this->perVerduras = perVerduras;}
    int getPerGranos() {return perGranos;}
    void setPerGranos(int perGranos) {this->perGranos = perGranos;}
    int getPerLacteos() {return perLacteos;}
    void setPerLacteos(int perLacteos) {this->perLacteos = perLacteos;}
    int getPerProteina() {return perProteina;}
    void setPerProteina(int perProteina) {this->perProteina = perProteina;}
    int getCaloriasFrutas() {return caloriasFrutas;}
    void setCaloriasFrutas(int caloriasFrutas) {this->caloriasFrutas = caloriasFrutas; }
    int getCaloriasVerduras() {return caloriasVerduras;}
    void setCaloriasVerduras(int caloriasVerduras) {this->caloriasVerduras = caloriasVerduras;}
    int getCaloriasGranos() {return caloriasGranos;}
    void setCaloriasGranos(int caloriasGranos) {this->caloriasGranos = caloriasGranos;}
    int getCaloriasLacteos() {return caloriasLacteos;}
    void setCaloriasLacteos(int caloriasLacteos) {this->caloriasLacteos = caloriasLacteos;}
    int getCaloriasProteina() {return caloriasProteina;}
    void setCaloriasProteina(int caloriasProteina) {this->caloriasProteina = caloriasProteina;}
    vector<Frutas> getFrutas() {return frutas;}
    void setFrutas(vector<Frutas> frutas) {this->frutas = frutas;}
    vector<Verdura> getVerduras() {return verduras;}
    void setVerduras(vector<Verdura> verduras) {this->verduras = verduras;}
    vector<Granos> getGranos() {return granos;}
    void setGranos(vector<Granos> granos) {this->granos = granos;}
    vector<Lacteos> getLacteos() {return lacteos;}
    void setLacteos(vector<Lacteos> lacteos) {this->lacteos = lacteos;}
    vector<Proteina> getProteinas() {return proteinas;}
    void setProteinas(vector<Proteina> proteinas) {this->proteinas = proteinas;}


};