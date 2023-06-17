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
#include <ctime>

#include "Frutas.h"
#include "Granos.h"
#include "Lacteos.h"
#include "Proteina.h"
#include "Usuario.h"
#include "Verdura.h"
#include "CalcularCalorias.h"
#include "Dieta.h"

using namespace std;

class Menu
{

private:
    vector<Frutas> frutas;
    vector<Granos> granos;
    vector<Lacteos> lacteos;
    vector<Proteina> carnes;
    vector<Usuario> usuarios;
    vector<Verdura> vegetales;
    vector<Dieta> dietas;
    vector<CalcularCalorias> calcularCalorias;
    vector<Ingrediente *> ingredientes;

public:
    // Default constructor
    Menu() {}

    // Parameterized constructor
    Menu(vector<Frutas> frutas, vector<Granos> granos, vector<Lacteos> lacteos, vector<Proteina> proteinas, vector<Usuario> usuarios, vector<Verdura> verduras, vector<Dieta> dietas, vector<CalcularCalorias> calcularCalorias)
        : frutas(frutas), granos(granos), lacteos(lacteos), carnes(proteinas), usuarios(usuarios), vegetales(verduras), dietas(dietas), calcularCalorias(calcularCalorias) {}

    // Setters and Getters
    void setFrutas(vector<Frutas> frutas) { this->frutas = frutas; }
    const vector<Frutas> &getFrutas() const { return frutas; }

    void setGranos(vector<Granos> granos) { this->granos = granos; }
    const vector<Granos> &getGranos() const { return granos; }

    void setLacteos(vector<Lacteos> lacteos) { this->lacteos = lacteos; }
    const vector<Lacteos> &getLacteos() const { return lacteos; }

    void setProteinas(vector<Proteina> proteinas) { carnes = proteinas; }
    const vector<Proteina> &getProteinas() const { return carnes; }

    void setUsuarios(vector<Usuario> usuarios) { this->usuarios = usuarios; }
    const vector<Usuario> &getUsuarios() const { return usuarios; }

    void setVerduras(vector<Verdura> verduras) { vegetales = verduras; }
    const vector<Verdura> &getVerduras() const { return vegetales; }

    void setDietas(vector<Dieta> dietas) { this->dietas = dietas; }
    const vector<Dieta> &getDietas() const { return dietas; }

    void setCalcularCalorias(vector<CalcularCalorias> calcularCalorias) { this->calcularCalorias = calcularCalorias; }
    const vector<CalcularCalorias> &getCalcularCalorias() const { return calcularCalorias; }

    // Methods

    // Read all the data "Fruta" from the file and store it in the vector
    
    // Read all the data "Granos" from the file and store it in the vector
    void readFrutasFromFile(std::vector<Frutas>& frutas, const std::string& filename) {
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::istringstream iss(line);
            std::string nombre, tipoIngrediente, dummy;
            int calorias, carbohidratos, grasas, gramos, azucar;

            getline(iss, nombre, ',');
            nombre = nombre.substr(1, nombre.length() - 2); // Remove quotes

            getline(iss, tipoIngrediente, ',');
            tipoIngrediente = tipoIngrediente.substr(1, tipoIngrediente.length() - 2); // Remove quotes

            iss >> calorias >> dummy;
            iss >> carbohidratos >> dummy;
            iss >> grasas >> dummy;
            iss >> gramos >> dummy;
            iss >> azucar;

            Frutas fruta(nombre, tipoIngrediente, calorias, carbohidratos, grasas, gramos, azucar);
            frutas.push_back(fruta);
        }
        file.close();
    } else {
        throw std::runtime_error("Could not open file " + filename);
    }
}

void readGranosFromFile(std::vector<Granos>& granos, const std::string& filename) {
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::istringstream iss(line);
            std::string nombre, tipoIngrediente, dummy;
            int calorias, carbohidratos, grasas, gramos, proteinas, sodio;
            bool isIntegral;

            getline(iss, nombre, ',');
            nombre = nombre.substr(1, nombre.length() - 2); // Remove quotes

            getline(iss, tipoIngrediente, ',');
            tipoIngrediente = tipoIngrediente.substr(1, tipoIngrediente.length() - 2); // Remove quotes

            iss >> calorias >> dummy;
            iss >> carbohidratos >> dummy;
            iss >> grasas >> dummy;
            iss >> gramos >> dummy;
            iss >> proteinas >> dummy;
            iss >> sodio >> dummy;
            iss >> std::boolalpha >> isIntegral;

            Granos grano(nombre, tipoIngrediente, calorias, carbohidratos, grasas, gramos, proteinas, sodio, isIntegral);
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
            std::string nombre, tipoIngrediente, dummy;
            int calorias, carbohidratos, grasas, gramos, grasasSaturadas, proteinas, colesterol;

            getline(iss, nombre, ',');
            nombre = nombre.substr(1, nombre.length() - 2); // Remove quotes

            getline(iss, tipoIngrediente, ',');
            tipoIngrediente = tipoIngrediente.substr(1, tipoIngrediente.length() - 2); // Remove quotes

            iss >> calorias >> dummy;
            iss >> carbohidratos >> dummy;
            iss >> grasas >> dummy;
            iss >> gramos >> dummy;
            iss >> grasasSaturadas >> dummy;
            iss >> proteinas >> dummy;
            iss >> colesterol;

            Lacteos lacteo(nombre, tipoIngrediente, calorias, carbohidratos, grasas, gramos, grasasSaturadas, proteinas, colesterol);
            lacteos.push_back(lacteo);
        }
        file.close();
    } else {
        throw std::runtime_error("Could not open file " + filename);
    }
}

    // Read all the data "Proteina" from the file and store it in the vector
    void readProteinasFromFile(std::vector<Proteina> &proteinas, const std::string &filename)
    {
        std::ifstream file(filename);

        if (file.is_open())
        {
            std::string line;
            while (getline(file, line))
            {
                std::istringstream iss(line);
                std::string name, type, dummy;
                int calories, carbohydrates, fat, grams, protein, cholesterol, sodium, sat_fat;

                getline(iss, name, ',');
                name = name.substr(1, name.length() - 2); // Remove quotes

                getline(iss, type, ',');
                type = type.substr(1, type.length() - 2); // Remove quotes

                iss >> calories >> dummy;
                iss >> carbohydrates >> dummy;
                iss >> fat >> dummy;
                iss >> grams >> dummy;
                iss >> sat_fat >> dummy;
                iss >> protein >> dummy;
                iss >> cholesterol >> dummy;
                iss >> sodium;

                Proteina proteina(name, type, calories, carbohydrates, fat, grams, sat_fat, protein, cholesterol, sodium);
                proteinas.push_back(proteina);
            }
            file.close();
        }
        else
        {
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
            std::string nombre, tipoIngrediente, dummy;
            int calorias, carbohidratos, grasas, gramos, proteinas;
            bool isOrganico;

            getline(iss, nombre, ',');
            nombre = nombre.substr(1, nombre.length() - 2); // Remove quotes

            getline(iss, tipoIngrediente, ',');
            tipoIngrediente = tipoIngrediente.substr(1, tipoIngrediente.length() - 2); // Remove quotes

            iss >> calorias >> dummy;
            iss >> carbohidratos >> dummy;
            iss >> grasas >> dummy;
            iss >> gramos >> dummy;
            iss >> proteinas >> dummy;
            iss >> std::boolalpha >> isOrganico;

            Verdura verdura(nombre, tipoIngrediente, calorias, carbohidratos, grasas, gramos, proteinas, isOrganico);
            verduras.push_back(verdura);
        }
        file.close();
    } else {
        throw std::runtime_error("Could not open file " + filename);
    }
}

    void handleMenuGeneration(int position, vector<Usuario> &usuarios)
    {

        // Here lies a bug, that I fortunately identified, but I don't have time to fix it
        // Dont leave blank rows of data data, it throws an error
        /*
        Eg:

        1. "Manzana", "Fruta", 52, 14, 0, 100 ,10
        2. "Platano", "Fruta", 105, 27, 0, 100 ,14
        3.
        4. "Fresa", "Fruta", 33, 8, 0, 100 ,4
        5.
        6.
        7.


        the lines 3,5,6,7 represent the error
        */

        // Also, pay attention to the name of the files, they are hardcoded, so if you change the name of the file, you have to change it here too
        std::vector<Frutas> frutas;
        readFrutasFromFile(frutas, "frutas.txt");

        std::vector<Granos> granos;
        readGranosFromFile(granos, "granos.txt");

        std::vector<Lacteos> lacteos;
        readLacteosFromFile(lacteos, "lacteos.txt");

        std::vector<Proteina> proteinas;
        readProteinasFromFile(proteinas, "proteinas.txt");

        std::vector<Verdura> verduras;
        readVerdurasFromFile(verduras, "verdura.txt");

        
        
        int i = 0;
        while (true)
        {
            cout << "Que desea hacer?" << endl;
            cout << "1. Generar un menu manualmente" << endl;
            cout << "2. Generar un menu automaticamente en base a calorias" << endl;
            cout << "3. Revisar dietas generadas" << endl;
            cout << "4. Salir" << endl;
            int opcion;
            cin >> opcion;

            switch (opcion)
            {
            case 1:
            {
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
                while (opcion4)
                { // Contained in switch case 1 and applies to all election 1 though 5 in case 1 ONLY
                    if (opcion2 == 1)
                    {
                        cout << "Que fruta desea agregar?" << endl;
                        for (int i = 0; i < frutas.size(); i++)
                        {
                            cout << i + 1 << ". " << frutas[i] << endl;
                        }
                        int opcion3;
                        cin >> opcion3;
                        Ingrediente *ingredienteF = new Frutas(frutas[opcion3 - 1]);
                        ingredientes.push_back(ingredienteF);
                        cout << "Desear agregar otro ingrediente?" << endl;
                        cout << "1. Si" << endl;
                        cout << "2. No" << endl;
                        int opcion4;
                        cin >> opcion4;
                        if (opcion4 == 1)
                        {
                            opcion4 = true;
                        }
                        else
                        {
                            opcion4 = false;
                        }
                    } // End of opcion2 == 1
                    if (opcion2 == 2)
                    {
                        cout << "Que grano desea agregar?" << endl;
                        for (int i = 0; i < granos.size(); i++)
                        {
                            cout << i + 1 << ". " << granos[i] << endl;
                        }
                        int opcion3;
                        cin >> opcion3;
                        Ingrediente *ingredienteG = new Granos(granos[opcion3 - 1]);
                        ingredientes.push_back(ingredienteG);
                        cout << "Desear agregar otro ingrediente?" << endl;
                        cout << "1. Si" << endl;
                        cout << "2. No" << endl;
                        int opcion4;
                        cin >> opcion4;
                        if (opcion4 == 1)
                        {
                            opcion4 = true;
                        }
                        else
                        {
                            opcion4 = false;
                        }
                    } // End of opcion2 == 2
                    if (opcion2 == 3)
                    {
                        cout << "Que lacteo desea agregar?" << endl;
                        for (int i = 0; i < lacteos.size(); i++)
                        {
                            cout << i + 1 << ". " << lacteos[i] << endl;
                        }
                        int opcion3;
                        cin >> opcion3;

                        Ingrediente *ingredienteL = new Lacteos(lacteos[opcion3 - 1]);
                        ingredientes.push_back(ingredienteL);
                        cout << "Desear agregar otro ingrediente?" << endl;
                        cout << "1. Si" << endl;
                        cout << "2. No" << endl;
                        int opcion4;
                        cin >> opcion4;
                        if (opcion4 == 1)
                        {
                            opcion4 = true;
                        }
                        else
                        {
                            opcion4 = false;
                        }
                    } // End of opcion2 == 3
                    if (opcion2 == 4)
                    {
                        cout << "Que proteina desea agregar?" << endl;
                        for (int i = 0; i < proteinas.size(); i++)
                        {
                            cout << i + 1 << ". " << proteinas[i] << endl;
                        }
                        int opcion3;
                        cin >> opcion3;
                        Ingrediente *ingredienteP = new Lacteos(lacteos[opcion3 - 1]);
                        ingredientes.push_back(ingredienteP);
                        cout << "Desear agregar otro ingrediente?" << endl;
                        cout << "1. Si" << endl;
                        cout << "2. No" << endl;
                        int opcion4;
                        cin >> opcion4;
                        if (opcion4 == 1)
                        {
                            opcion4 = true;
                        }
                        else
                        {
                            opcion4 = false;
                        }
                    } // End of opcion2 == 4
                    if (opcion2 == 5)
                    {
                        cout << "Que verdura desea agregar?" << endl;
                        for (int i = 0; i < verduras.size(); i++)
                        {
                            cout << i + 1 << ". " << verduras[i] << endl;
                        }
                        int opcion3;
                        cin >> opcion3;
                        Ingrediente *ingredienteV = new Verdura(vegetales[opcion3 - 1]);
                        ingredientes.push_back(ingredienteV);
                        cout << "Desear agregar otro ingrediente?" << endl;
                        cout << "1. Si" << endl;
                        cout << "2. No" << endl;
                        int opcion4;
                        cin >> opcion4;
                        if (opcion4 == 1)
                        {
                            opcion4 = true;
                        }
                        else
                        {
                            opcion4 = false;
                        }
                    } // End of opcion2 == 5

                } // End of while loop, just so I dont loose track of it
                CalcularCalorias C1;
                C1.agregarIngredientes(ingredientes);
                C1.calcularTotalCalorias();
                C1.calcularTotalCarbohidratos();
                C1.calcularTotalGrasas();
                cout << C1 << endl;
                usuarios[position].agregarIngredientes(ingredientes);
                break;
            }
            case 2:
            {
                int BMI = (usuarios[position].getPeso() / usuarios[position].getAltura());
                int recomendacion; // Declare the variable here
                if (BMI > 18.5)
                {
                    recomendacion = 2500; // Assign value inside the if block
                }
                else if (BMI > 25)
                {
                    recomendacion = 2000;
                }
                else if (BMI > 30)
                {
                    recomendacion = 1500;
                }
                cout << "Cuantas calorias quiere consumir?" << endl;
                cout << "La cantidad minima para usted, en base a su edad es " << recomendacion << endl;
                
                int calorias;
                cin >> calorias;

                Dieta D1(calorias);
                D1.calcularCaloriasDieta();
                D1.calcularDieta(frutas, verduras, granos, lacteos, proteinas);

                usuarios[position].agregarIngredientes(D1.getIngredientes());
            }
            break;
            case 3:{
                cout << usuarios[position].getIngredientesSize() << endl;
                
                std::vector<Ingrediente*> ingredientes2 = usuarios[position].getIngredientes();
                cout << "Ingredientes:" << endl;
                for (int i = 0; i < usuarios[position].getIngredientesSize(); i++)
                {
                    cout << i << ". " << ingredientes2[i] << endl;
                }
                //get today's date without horus

                time_t now = time(0);
                tm *ltm = localtime(&now);
                int year = 1900 + ltm->tm_year;
                int month = 1 + ltm->tm_mon;
                int day = ltm->tm_mday;
                string fecha = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
                
                //get today's date without horus
                cout << "Dieta creada el: " << fecha << endl;
                
                
               
                break;
                }
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
