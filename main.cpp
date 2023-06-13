/*
Proyecto aplicacion de dieta
Kirill Makienko Tkachenko
08/06/2023
*/

//Quiero mencionar brevemente que entre Chat-GPT y github Co-Pilot hicieron que este proyecto se hiciera en tiempo record.

//Todo

//Mandar toda la generacion del menu a una funcion o clase
//Hacer que el usuario pueda elegir que ingredientes quiere
//Hacer menu que calcule en base a calorias
//Hacer menu que calcule en base a carbohidratos
//Hacer menu que calcule en base a grasas
//Hacer algoritmo de calculo de calorias
//Hacer algoritmo de calculo de carbohidratos
//Hacer algoritmo de calculo de grasas
//Usuario no funciona no se porque
//Limpiar el codigo


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

using namespace std;

// function to register a user
void registerUser(vector<Usuario>& usuarios) {
    string name;
    int weight;
    float height;

    cout << "Ingrese su nombre: ";
    cin >> name;
    cout << "Ingrese su peso: ";
    cin >> weight;
    cout << "Ingrese su altura: ";
    cin >> height;

    Usuario usuario(name, weight, height);
    usuarios.push_back(usuario);
}

// function to search for a user by name
bool searchUser(const vector<Usuario>& usuarios, const string& name) {
    for (const auto& usuario : usuarios) {
        if (usuario.getNombre() == name) {
            return true;
        }
    }
    return false;
}

void readFrutasFromFile(std::vector<Frutas>& frutas, const std::string& filename) {
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::istringstream iss(line);
            std::string name, type, dummy;
            int calories, carbohydrates, fat, protein;

            getline(iss, name, ',');
            name = name.substr(1, name.length() - 2);  // Remove quotes

            getline(iss, dummy, ',');  // Skip type

            iss >> dummy >> calories >> dummy;
            iss >> dummy >> carbohydrates >> dummy;
            iss >> dummy >> fat >> dummy;
            iss >> protein;

            Frutas fru(name, type, calories, carbohydrates, fat, protein);
            frutas.push_back(fru);
        }
        file.close();
    } else {
        throw std::runtime_error("Could not open file " + filename);
    }
}

void readGranosFromFile(vector<Granos>& granos, const string& filename) {
    ifstream file(filename);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string name, type, dummy;
            int calories, carbohydrates, fat, protein, fiber;
            bool isWholeGrain;

            getline(iss, name, ',');
            name = name.substr(1, name.length() - 2);  // Remove quotes

            getline(iss, dummy, ',');  // Skip type

            iss >> dummy >> calories >> dummy;
            iss >> dummy >> carbohydrates >> dummy;
            iss >> dummy >> fat >> dummy;
            iss >> dummy >> protein >> dummy;
            iss >> dummy >> fiber >> dummy;
            iss >> isWholeGrain;

            Granos grano(name, type, calories, carbohydrates, fat, protein, fiber, isWholeGrain);
            granos.push_back(grano);
        }
        file.close();
    } else {
        throw std::runtime_error("Could not open file " + filename);
    }
}



// function to handle menu generation options
void handleMenuGeneration() {
    while (true) {
        cout << "Que desea hacer?" << endl;
        cout << "1. Generar un menu manualmente" << endl;
        cout << "2. Generar un menu automaticamente en base a calorias" << endl;
        cout << "3. Generar un menu automaticamente en base a proteinas" << endl;
        cout << "4. Salir" << endl;
        int opcion;
        cin >> opcion;

        switch (opcion) {
            case 1:
                // Generate menu manually
                // ...

                break;
            case 2:
                // Generate menu based on calories
                // ...

                break;
            case 3:
                // Generate menu based on protein
                // ...

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

int main() {
    // Create a vector of users
    vector<Usuario> usuarios;
    Usuario usuario1("Kirill", 100, 1.80);
    usuarios.push_back(usuario1);

    // Create a vector of Frutas
    vector<Frutas> frutas;
    // Read the file and store the data in the vector
    readFrutasFromFile(frutas, "fruta.txt");

    // Create a vector of Granos
    vector<Granos> granos;
    // Read the file and store the data in the vector
    readGranosFromFile(granos, "granos.txt");

    // Create a vector of Lacteos
    vector<Lacteos> lacteos;
    // Read the file and store the data in the vector

   

    // Create a vector of Ingrediente to store the ingredients
    vector<Ingrediente> ingredientes;

    cout << "Bienvenido a la aplicacion de dietas" << endl;
    cout << "Ya esta registrado?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    int respuesta;
    cin >> respuesta;

    if (respuesta == 1) {
        cout << "Ingrese su nombre de usuario" << endl;
        string nombre;
        cin >> nombre;

        bool userFound = searchUser(usuarios, nombre);
        if (userFound) {
            cout << "Bienvenido " << nombre << endl;
            handleMenuGeneration();
        } else {
            cout << "Usuario no encontrado. Por favor, registrese." << endl;
            registerUser(usuarios);
        }
    } else if (respuesta == 2) {
        registerUser(usuarios);
    } else {
        cout << "Opcion invalida" << endl;
    }

    return 0;
}
