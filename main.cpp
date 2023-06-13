/*
Proyecto aplicacion de dieta
Kirill Makienko Tkachenko
08/06/2023
*/

/*
    Estimada Dra. Monica (o usuario que por desgracia se ha encontrado con este repo), BIENVENIDOS A MI MAGNUM OPUS DE METER INSTRUCCIONES A DIFERENTES IAS Y LUEGO
    ESTAR MAS O MENOS 30 MINUTOS RESOLVIENDO QUE HICIERON MAL, espero que este codigo sea de su agrado, me voy a permitir hacerles un espoiler de esta gran 
    obra de arte, este codigo esta hecho con la intencion de ser lo mas modular posible, en lo cual creo que falla de manera espectacular ya que no va mas alla
    de lo estandar para escribir codigo con el paradigma de OOP, pero bueno, en este codigo tambien va a encontrar cumbias, Fito Olivares, mucha cumbia, mucha cumbia,
    y un poco de cumbia, tambien frustracion por querer hacer todo en un dia aun que cuando escribo esto todavia hay como 4 dias para la entrega o perfecta desesperacion
    por el hecho de usar Github Copilot que de vez en cuando es MUY, PERO MUUUY MOLESTO pero a la vez me ahorra tanto tiempo que estoy dispuesto a aguantarlo 
    aun que sea como tu primito de 5 años que es HIPER castroso pero es la llave para caerle bien a tu tia y que te de dinero, en fin, espero que disfrute este codigo
    tanto como yo (sorprendentemente) disfrute escribiendolo, y si no, pues que se le va a hacer, no se puede complacer a todo el mundo, y si no le gusta, pues que se le va a hacer
    Y gracias a Copilot por escribir la ultima oracion

    Tambien quiero agradecer a personas que me han ayudado en mi camino del heroe de este codigo como el bueno del Chambotas (O chambitas para las comadres), el Senior del Chuy (con maestria en Todologia), 
    el micho, ChatGPT, StackOverflow, GithubCopilot y las preguntas random que le hago a Dultez y Desireeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee, pero especialmente a la Dra. Monica porque 
    sin sus clases ni me hubiera aventado menuda obra maestra.
*/

//Todo


//Hacer menu que calcule en base a calorias
//Hacer menu que calcule en base a carbohidratos
//Hacer menu que calcule en base a grasas
//Hacer algoritmo de calculo de calorias
//Hacer algoritmo de calculo de carbohidratos
//Hacer algoritmo de calculo de grasas



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

// Function to search the position of a user by name
int searchUserPosition(const vector<Usuario>& usuarios, const string& name) {
    for (int i = 0; i < usuarios.size(); i++) {
        if (usuarios[i].getNombre() == name) {
            return i;
        }
    }
    return -1;
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

//Read all the data "Fruta" from the file and store it in the vector
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
//Read all the data "Granos" from the file and store it in the vector
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
//Read all the data "Lacteos" from the file and store it in the vector
void readLacteosFromFile(std::vector<Lacteos>& lacteos, const std::string& filename) {
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::istringstream iss(line);
            std::string name, type, dummy;
            int calories, carbohydrates, fat, protein, fiber, sodium;

            getline(iss, name, ',');
            name = name.substr(1, name.length() - 2);  // Remove quotes

            getline(iss, dummy, ',');  // Skip type

            iss >> dummy >> calories >> dummy;
            iss >> dummy >> carbohydrates >> dummy;
            iss >> dummy >> fat >> dummy;
            iss >> dummy >> protein >> dummy;
            iss >> dummy >> fiber >> dummy;
            iss >> sodium;

            Lacteos lacteo(name, type, calories, carbohydrates, fat, protein, fiber, sodium);
            lacteos.push_back(lacteo);
        }
        file.close();
    } else {
        throw std::runtime_error("Could not open file " + filename);
    }
}

//Read all the data "Proteina" from the file and store it in the vector
void readProteinasFromFile(std::vector<Proteina>& proteinas, const std::string& filename) {
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::istringstream iss(line);
            std::string name, type, dummy;
            int calories, carbohydrates, fat, protein, cholesterol, sodium, fiber;

            getline(iss, name, ',');
            name = name.substr(1, name.length() - 2);  // Remove quotes

            getline(iss, dummy, ',');  // Skip type

            iss >> dummy >> calories >> dummy;
            iss >> dummy >> carbohydrates >> dummy;
            iss >> dummy >> fat >> dummy;
            iss >> dummy >> protein >> dummy;
            iss >> dummy >> cholesterol >> dummy;
            iss >> dummy >> sodium >> dummy;
            iss >> fiber;

            Proteina proteina(name, type, calories, carbohydrates, fat, protein, cholesterol, sodium, fiber);
            proteinas.push_back(proteina);
        }
        file.close();
    } else {
        throw std::runtime_error("Could not open file " + filename);
    }
}

void readVerdurasFromFile(std::vector<Verdura>& verduras, const std::string& filename) {
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::istringstream iss(line);
            std::string name, type, dummy;
            int calories, carbohydrates, fat, protein;
            bool isGreen;

            getline(iss, name, ',');
            name = name.substr(1, name.length() - 2);  // Remove quotes

            getline(iss, dummy, ',');  // Skip type

            iss >> dummy >> calories >> dummy;
            iss >> dummy >> carbohydrates >> dummy;
            iss >> dummy >> fat >> dummy;
            iss >> dummy >> protein >> dummy;
            iss >> isGreen;

            Verdura verdura(name, type, calories, carbohydrates, fat, protein, isGreen);
            verduras.push_back(verdura);
        }
        file.close();
    } else {
        throw std::runtime_error("Could not open file " + filename);
    }
}



// function to handle menu generation options
void handleMenuGeneration(vector<Ingrediente>& ingredientes, vector<Frutas>& frutas, vector<Granos>& granos, vector<Lacteos>& lacteos, vector<Proteina>& proteinas, vector<Verdura>& verduras, size_t position, vector<Usuario>& usuarios) {
    while (true) {
        cout << "Que desea hacer?" << endl;
        cout << "1. Generar un menu manualmente" << endl;
        cout << "2. Generar un menu automaticamente en base a calorias" << endl;
        cout << "3. Generar un menu automaticamente en base a proteinas" << endl;
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
                        ingredientes.push_back(frutas[opcion3 - 1]);
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
                        ingredientes.push_back(granos[opcion3 - 1]);
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
                        ingredientes.push_back(lacteos[opcion3 - 1]);
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
                        ingredientes.push_back(proteinas[opcion3 - 1]);
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
                        ingredientes.push_back(verduras[opcion3 - 1]);
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
                ;
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
            case 2:
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
    readLacteosFromFile(lacteos, "lacteos.txt");

    // Create a vector of Carnes
    vector<Proteina> carnes;
    // Read the file and store the data in the vector
    readProteinasFromFile(carnes, "proteina.txt");

    // Create a vector of Vegetales
    vector<Verdura> vegetales;
    // Read the file and store the data in the 
    readVerdurasFromFile(vegetales, "verduras.txt");

   

    // Create a vector of Ingrediente to store the ingredients
    vector<Ingrediente> ingredientes;


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//a REALLY STUPID RANT, FEEL FREE TO DONT READ
/*
There posibly is a way to register an infinite amount of people, even if they arent registered but i`ve already lost so much time trying to figure out how to do it that i just gave up
So now everybody must conform to the fact that if you arent registerd you can do the trick and act as if you are a 5 yo and say that you registered but you aren`t, because if you do it twice in a row the program will exit
and honestly I have other things to worry about than some stupid perk of this language that the thing that I write dosent work EXACTLLY how I want and I`m getting equally as annoyed because github Copilot is
trying to autocomplete almost ever GODDAMN word in this rant that I want to write for myself so that I feel that I have the sufficent energy to try and one shot this all in a day even though I have the whole week to finish this.
TL;DR. I Hate cpp.

AND THE FACT THAT JUST NOW I NOTICE THAT ALL THE LOGIC I SPENT AN HOUR AND CHANGE JUST VANISHED BECAUSE I WAS SUFFICIENTLY F RECKLESS TO DELETE IT BECAUSE I JUST THOUGHT THAT IT WAS COMENTED DUPLICATE CODE WHYWHYWHYWHYWHYWHYWHYWHYWHYWHYWHYWHYWHYWHYWHYWHYWHYWHYWHYWHYWHYWHYWHY

Why I am writing this in english

Also I AM very WORRIED not STRESSED to have a really clean code BECAUSE IF NOT IM NEVER GETTING A 10 ON THIS PROJECT AND THAT SOMETHING I REALLY WANT ALTHOUGH THIS CLASS IS ONLY WORTH 1 CREDIT BUT STILL HUSVIFRUFBVLUIAVDSLUIADWVSLUHIASLHULHIUAWEHLUAEBHAWREHLGUOAHWLEBLH UOIAWELHUIAEBLUHOI
And I'm getting annoyed that I dont have a trackpad to scroll horizontally and have to go all the way to the little scroll bar on the bottom, to miss it and to try to aim again just to miss it again COPILOT STOP TYING TO AUTOCOMPLETE MY RANT AFDNIOWDNGHAUSOJUNBJHOGSWDFUBOHGDSWUBOHGDUOHBUHO
*/
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*



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
            int position = searchUserPosition(usuarios, nombre); //Search the position of the user to be able to add the diet to their account
            cout << "Bienvenido " << nombre << endl;
            handleMenuGeneration(ingredientes, frutas, granos, lacteos, carnes, vegetales, position, usuarios);
        } else {
            cout << "Usuario no encontrado. Por favor, registrese." << endl;
            registerUser(usuarios);
        }
    } else if (respuesta == 2) {
        registerUser(usuarios);
        respuesta = 1;
    } else {
        cout << "Opcion invalida" << endl;
    }

    return 0;
}
