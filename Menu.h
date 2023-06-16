/*
Proyecto aplicacion de dieta
Kirill Makienko Tkachenko
08/06/2023
*/

#pragma once


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>


#include "Frutas.h"
#include "Granos.h"
#include "Lacteos.h"
#include "Proteina.h"
#include "Usuario.h"
#include "Verdura.h"
#include "CalcularCalorias.h"
#include "Dieta.h"

using namespace std;

class Menu {

private:
    vector<Frutas> frutas;
    vector<Granos> granos;
    vector<Lacteos> lacteos;
    vector<Proteina> carnes;
    vector<Usuario> usuarios;
    vector<Verdura> vegetales;
    vector<Dieta> dietas;
    vector<CalcularCalorias> calcularCalorias;
    vector<Ingrediente*> ingredientes;

public:

    //Default constructor
    Menu() {}

    //Parameterized constructor
    Menu(vector<Frutas> frutas, vector<Granos> granos, vector<Lacteos> lacteos, vector<Proteina> proteinas, vector<Usuario> usuarios, vector<Verdura> verduras, vector<Dieta> dietas, vector<CalcularCalorias> calcularCalorias)
        : frutas(frutas), granos(granos), lacteos(lacteos), carnes(proteinas), usuarios(usuarios), vegetales(verduras), dietas(dietas), calcularCalorias(calcularCalorias) {}

    //Setters and Getters
    void setFrutas(vector<Frutas> frutas) { this->frutas = frutas; }
    const vector<Frutas>& getFrutas() const { return frutas; }

    void setGranos(vector<Granos> granos) { this->granos = granos; }
    const vector<Granos>& getGranos() const { return granos; }

    void setLacteos(vector<Lacteos> lacteos) { this->lacteos = lacteos; }
    const vector<Lacteos>& getLacteos() const { return lacteos; }

    void setProteinas(vector<Proteina> proteinas) { carnes = proteinas; }
    const vector<Proteina>& getProteinas() const { return carnes; }

    void setUsuarios(vector<Usuario> usuarios) { this->usuarios = usuarios; }
    const vector<Usuario>& getUsuarios() const { return usuarios; }

    void setVerduras(vector<Verdura> verduras) { vegetales = verduras; }
    const vector<Verdura>& getVerduras() const { return vegetales; }

    void setDietas(vector<Dieta> dietas) { this->dietas = dietas; }
    const vector<Dieta>& getDietas() const { return dietas; }

    void setCalcularCalorias(vector<CalcularCalorias> calcularCalorias) { this->calcularCalorias = calcularCalorias; }
    const vector<CalcularCalorias>& getCalcularCalorias() const { return calcularCalorias; }

    //Methods

    
    
// Read all the data "Fruta" from the file and store it in the vector
void readFrutasFromFile(std::vector<Frutas>& frutas, const std::string& filename) {
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::istringstream iss(line);
            std::string name, type, dummy;
            int calories, carbohydrates, fat, protein, grams;

            getline(iss, name, ',');
            name = name.substr(1, name.length() - 2);  // Remove quotes

            getline(iss, dummy, ',');  // Skip type

            iss >> dummy >> calories >> dummy;
            iss >> dummy >> carbohydrates >> dummy;
            iss >> dummy >> fat >> dummy;
            iss >> dummy >> grams >> dummy;
            iss >> protein;

            Frutas fru(name, type, calories, carbohydrates, fat, grams, protein);
            frutas.push_back(fru);
        }
        file.close();
    } else {
        throw std::runtime_error("Could not open file " + filename);
    }
}

// Read all the data "Granos" from the file and store it in the vector
void readGranosFromFile(std::vector<Granos>& granos, const std::string& filename) {
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::istringstream iss(line);
            std::string name, type, dummy;
            int calories, carbohydrates, fat, protein, fiber, grams;
            bool isWholeGrain;

            getline(iss, name, ',');
            name = name.substr(1, name.length() - 2);  // Remove quotes

            getline(iss, dummy, ',');  // Skip type

            iss >> dummy >> calories >> dummy;
            iss >> dummy >> carbohydrates >> dummy;
            iss >> dummy >> fat >> dummy;
            iss >> dummy >> grams >> dummy;
            iss >> dummy >> protein >> dummy;
            iss >> dummy >> fiber >> dummy;
            iss >> isWholeGrain;

            Granos grano(name, type, calories, carbohydrates, fat, grams, protein, fiber, isWholeGrain);
            granos.push_back(grano);
        }
        file.close();
    } else {
        throw std::runtime_error("Could not open file " + filename);
    }
}

// Read all the data "Lacteos" from the file and store it in the vector
void readLacteosFromFile(std::vector<Lacteos>& lacteos, const std::string& filename) {
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::istringstream iss(line);
            std::string name, type, dummy;
            int calories, carbohydrates, fat, protein, fiber, sodium, grams;

            getline(iss, name, ',');
            name = name.substr(1, name.length() - 2);  // Remove quotes

            getline(iss, dummy, ',');  // Skip type

            iss >> dummy >> calories >> dummy;
            iss >> dummy >> carbohydrates >> dummy;
            iss >> dummy >> fat >> dummy;
            iss >> dummy >> grams >> dummy;
            iss >> dummy >> protein >> dummy;
            iss >> dummy >> fiber >> dummy;
            iss >> sodium;

            Lacteos lacteo(name, type, calories, carbohydrates, fat, grams, protein, fiber, sodium);
            lacteos.push_back(lacteo);
        }
        file.close();
    } else {
        throw std::runtime_error("Could not open file " + filename);
    }
}

// Read all the data "Proteina" from the file and store it in the vector
void readProteinasFromFile(std::vector<Proteina>& proteinas, const std::string& filename) {
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::istringstream iss(line);
            std::string name, type, dummy;
            int calories, carbohydrates, fat, grams, protein, cholesterol, sodium, fiber;

            getline(iss, name, ',');
            name = name.substr(1, name.length() - 2);  // Remove quotes

            getline(iss, dummy, ',');  // Skip type

            iss >> dummy >> calories >> dummy;
            iss >> dummy >> carbohydrates >> dummy;
            iss >> dummy >> fat >> dummy;
            iss >> dummy >> grams >> dummy;
            iss >> dummy >> protein >> dummy;
            iss >> dummy >> cholesterol >> dummy;
            iss >> dummy >> sodium >> dummy;
            iss >> fiber;

            Proteina proteina(name, type, calories, carbohydrates, fat, grams, protein, cholesterol, sodium, fiber);
            proteinas.push_back(proteina);
        }
        file.close();
    } else {
        throw std::runtime_error("Could not open file " + filename);
    }
}

// Read all the data "Verdura" from the file and store it in the vector
void readVerdurasFromFile(std::vector<Verdura>& verduras, const std::string& filename) {
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::istringstream iss(line);
            std::string name, type, dummy;
            int calories, carbohydrates, fat, protein, grams;
            bool isGreen;

            getline(iss, name, ',');
            name = name.substr(1, name.length() - 2);  // Remove quotes

            getline(iss, dummy, ',');  // Skip type

            iss >> dummy >> calories >> dummy;
            iss >> dummy >> carbohydrates >> dummy;
            iss >> dummy >> fat >> dummy;
            iss >> dummy >> grams >> dummy;
            iss >> dummy >> protein >> dummy;
            iss >> isGreen;

            Verdura verdura(name, type, calories, carbohydrates, fat, grams, protein, isGreen);
            verduras.push_back(verdura);
        }
        file.close();
    } else {
        throw std::runtime_error("Could not open file " + filename);
    }
}


void handleMenuGeneration(size_t position, vector<Usuario>& usuarios) {
    
    std::vector<Frutas> frutas;
    readFrutasFromFile(frutas, "frutas.txt");

    std::vector<Granos> granos;
    readGranosFromFile(granos, "granos.txt");

    std::vector<Lacteos> lacteos;
    readLacteosFromFile(lacteos, "lacteos.txt");

    std::vector<Proteina> proteinas;
    readProteinasFromFile(proteinas, "proteina.txt");

    std::vector<Verdura> verduras;
    readVerdurasFromFile(verduras, "verduras.txt");

    while (true) {
        cout << "Que desea hacer?" << endl;
        cout << "1. Generar un menu manualmente" << endl;
        cout << "2. Generar un menu automaticamente en base a calorias" << endl;
        cout << "3. Revisar dietas generadas" << endl;
        cout << "4. Salir" << endl;
        int opcion;
        cin >> opcion;

        switch (opcion) {
            case 1: {
                // Generate menu manually
                cout << "Que ingrediente desea agregar?" << endl;
                cout << "1. Fruta" << endl;
                cout << "2. Grano" << endl;
                cout << "3. Lacteo" << endl;
                cout << "4. Proteina" << endl;
                cout << "5. Verdura" << endl;
                int opcion2;
                cin >> opcion2;
                bool opcion4 = true;
                while(opcion4){ //Contained in switch case 1 and applies to all election 1 though 5 in case 1 ONLY
                    if(opcion2 == 1){
                        cout << "Que fruta desea agregar?" << endl;
                        for (int i = 0; i < frutas.size(); i++) {
                            cout << i + 1 << ". " << frutas[i] << endl;
                        }
                        int opcion3;
                        cin >> opcion3;
                        Ingrediente* ingredienteF = new Frutas(frutas[opcion3 - 1]);
                        ingredientes.push_back(ingredienteF);
                        cout << "Desear agregar otro ingrediente?" << endl;
                        cout << "1. Si" << endl;
                        cout << "2. No" << endl;
                        int opcion4;
                        cin >> opcion4;
                        if(opcion4 == 1){
                            opcion4 = true;
                        }else{
                            opcion4 = false;
                        }
                    }//End of opcion2 == 1
                if(opcion2 == 2){
                        cout << "Que grano desea agregar?" << endl;
                        for (int i = 0; i < granos.size(); i++) {
                            cout << i + 1 << ". " << granos[i] << endl;
                        }
                        int opcion3;
                        cin >> opcion3;
                        Ingrediente* ingredienteG = new Granos(granos[opcion3 - 1]);
                        ingredientes.push_back(ingredienteG);
                        cout << "Desear agregar otro ingrediente?" << endl;
                        cout << "1. Si" << endl;
                        cout << "2. No" << endl;
                        int opcion4;
                        cin >> opcion4;
                        if(opcion4 == 1){
                            opcion4 = true;
                        }else{
                            opcion4 = false;
                        }
                    }//End of opcion2 == 2
                if(opcion2 == 3){
                        cout << "Que lacteo desea agregar?" << endl;
                        for (int i = 0; i < lacteos.size(); i++) {
                            cout << i + 1 << ". " << lacteos[i] << endl;
                        }
                        int opcion3;
                        cin >> opcion3;
                        
                        Ingrediente* ingredienteL = new Lacteos(lacteos[opcion3 - 1]);
                        ingredientes.push_back(ingredienteL);
                        cout << "Desear agregar otro ingrediente?" << endl;
                        cout << "1. Si" << endl;
                        cout << "2. No" << endl;
                        int opcion4;
                        cin >> opcion4;
                        if(opcion4 == 1){
                            opcion4 = true;
                        }else{
                            opcion4 = false;
                        }
                    }//End of opcion2 == 3
                if(opcion2 == 4){
                        cout << "Que proteina desea agregar?" << endl;
                        for (int i = 0; i < proteinas.size(); i++) {
                            cout << i + 1 << ". " << proteinas[i] << endl;
                        }
                        int opcion3;
                        cin >> opcion3;
                        Ingrediente* ingredienteP = new Lacteos(lacteos[opcion3 - 1]);
                        ingredientes.push_back(ingredienteP);
                        cout << "Desear agregar otro ingrediente?" << endl;
                        cout << "1. Si" << endl;
                        cout << "2. No" << endl;
                        int opcion4;
                        cin >> opcion4;
                        if(opcion4 == 1){
                            opcion4 = true;
                        }else{
                            opcion4 = false;
                        }
                    }//End of opcion2 == 4
                if(opcion2 == 5){
                        cout << "Que verdura desea agregar?" << endl;
                        for (int i = 0; i < verduras.size(); i++) {
                            cout << i + 1 << ". " << verduras[i] << endl;
                        }
                        int opcion3;
                        cin >> opcion3;
                        Ingrediente* ingredienteV = new Verdura(vegetales[opcion3 - 1]);
                        ingredientes.push_back(ingredienteV);
                        cout << "Desear agregar otro ingrediente?" << endl;
                        cout << "1. Si" << endl;
                        cout << "2. No" << endl;
                        int opcion4;
                        cin >> opcion4;
                        if(opcion4 == 1){
                            opcion4 = true;
                        }else{
                            opcion4 = false;
                        }
                    }//End of opcion2 == 5
                
                }//End of while loop, just so I dont loose track of it
                CalcularCalorias C1;
                C1.agregarIngredientes(ingredientes);
                C1.calcularTotalCalorias();
                C1.calcularTotalCarbohidratos();
                C1.calcularTotalGrasas();
                cout << C1 << endl;
                usuarios[position].agregarIngredientes(ingredientes);
                break;
                }   
            case 2: {
                int BMI = (usuarios[position].getPeso() /  usuarios[position].getAltura());
                int recomendacion;  // Declare the variable here
                if(BMI > 18.5){
                    recomendacion = 2500;  // Assign value inside the if block
                }
                else if(BMI > 25){
                    recomendacion = 2000;
                }
                else if(BMI > 30){
                    recomendacion = 1500;
                }
                cout << "Cuantas calorias quiere consumir?" << endl;
                cout << "La cantidad minima para usted, en base a su edad es " << recomendacion << endl;
                cout << "La dieta minma es de 500 Calorias" << endl; 
                int calorias;
                cin >> calorias;
                Dieta D1(calorias, frutas, verduras, granos, lacteos, proteinas);
                D1.calcularCaloriasDieta();
                D1.calcularDieta(frutas, verduras, granos, lacteos, proteinas);
                usuarios[position].agregarIngredientes(D1.getIngredientes());
                
                


               
                }
                break;
            case 3:
                // Generate menu based on protein
                // ...
                cout << "algo" << endl;
                break;
            case 4:
                // Exit the program
                exit(0);
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
    }
}





};
