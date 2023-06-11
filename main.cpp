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

//Include our custom libraries

#include "Frutas.h"
#include "Granos.h"
#include "Lacteos.h"
#include "Proteina.h"
#include "Usuario.h"
#include "Verdura.h"
#include "CalcularCalorias.h"


using namespace std;

int main(){

    //Create a vector os users
    vector<Usuario> usuarios;

    //Declare a vector of frutas
    vector<Frutas> frutas;  

    //Generate the fruits
    Frutas manzana("Manzana", "Fruta", 52, 14, 0, 10);
    Frutas platano("Platano", "Fruta", 105, 27, 0, 14);
    Frutas fresa("Fresa", "Fruta", 33, 8, 0, 4);
    Frutas uva("Uva", "Fruta", 104, 27, 0, 23);
    Frutas naranja("Naranja", "Fruta", 62, 15, 0, 12);
    Frutas pera("Pera", "Fruta", 101, 27, 0, 17);
    Frutas mango("Mango", "Fruta", 99, 25, 0, 25);
    Frutas sandia("Sandia", "Fruta", 30, 8, 0, 6);
    Frutas melon("Melon", "Fruta", 30, 8, 0, 6);
    Frutas kiwi("Kiwi", "Fruta", 42, 11, 0, 8);
    Frutas limon("Limon", "Fruta", 29, 9, 0, 2);
    Frutas papaya("Papaya", "Fruta", 43, 11, 0, 8);
    Frutas cereza("Cereza", "Fruta", 50, 13, 0, 10);
    Frutas arandano("Arandano", "Fruta", 57, 15, 0, 12);
    Frutas frambuesa("Frambuesa", "Fruta", 52, 14, 0, 10);
    //Add the fruits to the vector of fruits
    frutas.push_back(manzana);
    frutas.push_back(platano);
    frutas.push_back(fresa);
    frutas.push_back(uva);
    frutas.push_back(naranja);
    frutas.push_back(pera);
    frutas.push_back(mango);
    frutas.push_back(sandia);
    frutas.push_back(melon);
    frutas.push_back(kiwi);
    frutas.push_back(limon);
    frutas.push_back(papaya);
    frutas.push_back(cereza);
    frutas.push_back(arandano);
    frutas.push_back(frambuesa);


    //Declare a vector of granos
    vector<Granos> granos;

    //Generate the grains
    Granos arroz("Arroz", "Grano", 130, 28, 0, 2, 6, true);
    Granos avena("Avena", "Grano", 389, 66, 0, 17, 2, false);
    Granos cebada("Cebada", "Grano", 354, 73, 0, 12, 2, true);
    Granos centeno("Centeno", "Grano", 335, 72, 0, 12, 2, true);
    Granos maiz("Maiz", "Grano", 365, 76, 0, 10, 4, false);
    Granos mijo("Mijo", "Grano", 378, 73, 0, 11, 1, true);
    Granos quinoa("Quinoa", "Grano", 368, 64, 0, 14, 6, false);
    Granos trigo("Trigo", "Grano", 340, 72, 0, 12, 2, true);
    Granos trigoSarraceno("Trigo Sarraceno", "Grano", 343, 72, 0, 13, 2, true);

    //Add the grains to the vector of grains

    granos.push_back(arroz);
    granos.push_back(avena);
    granos.push_back(cebada);
    granos.push_back(centeno);
    granos.push_back(maiz);
    granos.push_back(mijo);
    granos.push_back(quinoa);
    granos.push_back(trigo);
    granos.push_back(trigoSarraceno);

    //Declare a vector of lacteos
    vector<Lacteos> lacteos; 

    //Generate the dairy products with the following parameters:
    //string name, string type, int calories, int carbohydrates, int fat, int saturatedFat, int protein, int cholesterol

    Lacteos leche("Leche", "Lacteo", 61, 5, 3, 2, 3, 10);
    Lacteos queso("Queso", "Lacteo", 402, 1, 33, 21, 25, 105);
    Lacteos yogurt("Yogurt", "Lacteo", 59, 5, 3, 2, 3, 10);
    Lacteos mantequilla("Mantequilla", "Lacteo", 717, 0, 81, 51, 1, 215);
    Lacteos crema("Crema", "Lacteo", 340, 4, 35, 22, 3, 105);
    Lacteos helado("Helado", "Lacteo", 137, 14, 8, 5, 2, 29);
    Lacteos lecheC("Leche de Cabra", "Lacteo", 69, 5, 4, 3, 3, 11);
    Lacteos lecheA("Leche de Almendra", "Lacteo", 39, 2, 3, 0, 1, 0);
    Lacteos lecheS("Leche de Soya", "Lacteo", 54, 4, 3, 0, 4, 0);
    

    //Add the dairy products to the vector of dairy products
    lacteos.push_back(leche);
    lacteos.push_back(queso);
    lacteos.push_back(yogurt);
    lacteos.push_back(mantequilla);
    lacteos.push_back(crema);
    lacteos.push_back(helado);
    lacteos.push_back(lecheC);
    lacteos.push_back(lecheA);
    lacteos.push_back(lecheS);


    //Declare a vector of proteinas
    vector<Proteina> proteinas;

    //Generate the proteins with the following parameters:
    //string name, string type, int calories, int carbohydrates, int fat, int saturatedFat, int protein, int cholesterol, int sodium

    Proteina pavo("Pavo", "Proteina", 189, 0, 0, 0, 28, 62, 0);
    Proteina pollo("Pollo", "Proteina", 239, 0, 0, 0, 27, 73, 0);
    Proteina pescado("Pescado", "Proteina", 206, 0, 0, 0, 22, 58, 0);
    Proteina huevos("Huevos", "Proteina", 155, 1, 11, 3, 13, 373, 124);
    Proteina tofu("Tofu", "Proteina", 76, 2, 4, 1, 9, 0, 8);
    Proteina lentejas("Lentejas", "Proteina", 116, 20, 0, 0, 9, 0, 2);
    Proteina garbanzos("Garbanzos", "Proteina", 164, 27, 3, 0, 9, 0, 2);
    Proteina frijoles("Frijoles", "Proteina", 341, 63, 1, 0, 21, 0, 2);
    Proteina carne("Carne", "Proteina", 250, 0, 0, 0, 26, 93, 0);
    
    //Add the proteins to the vector of proteins
    proteinas.push_back(carne);
    proteinas.push_back(pavo);
    proteinas.push_back(pollo);
    proteinas.push_back(pescado);
    proteinas.push_back(huevos);
    proteinas.push_back(tofu);
    proteinas.push_back(lentejas);
    proteinas.push_back(garbanzos);
    proteinas.push_back(frijoles);
    
    //Whats the serving size of all the foods?
    //1 serving of grains = 1/2 cup
    //1 serving of dairy = 1 cup
    //1 serving of protein = 1 oz
    //1 serving of vegetables = 1 cup
    //1 serving of fruit = 1 cup

    //How much is that in grams?
    //1 serving of grains = 16 grams
    //1 serving of dairy = 225 grams
    //1 serving of protein = 28 grams
    //1 serving of vegetables = 85 grams
    //1 serving of fruit = 140 grams


    //Declare a vector of verduras
    vector<Verdura> verduras;

    //Generate the vegetables with the following parameters:
    //string name, string type, int calories, int carbohydrates, int fat, int protein, bool Organic

    Verdura zanahoria("Zanahoria", "Verdura", 25, 6, 0, 1, true);
    Verdura brocoli("Brocoli", "Verdura", 31, 6, 0, 3, true);
    Verdura espinaca("Espinaca", "Verdura", 23, 4, 0, 3, true);
    Verdura tomate("Tomate", "Verdura", 22, 5, 0, 1, true);
    Verdura cebolla("Cebolla", "Verdura", 40, 9, 0, 1, true);
    Verdura lechuga("Lechuga", "Verdura", 15, 3, 0, 1, true);
    Verdura pimiento("Pimiento", "Verdura", 40, 9, 0, 1, true);
    Verdura calabaza("Calabaza", "Verdura", 31, 7, 0, 1, true);
    Verdura coliflor("Coliflor", "Verdura", 25, 5, 0, 2, true);

    //Add the vegetables to the vector of vegetables
    verduras.push_back(zanahoria);
    verduras.push_back(brocoli);
    verduras.push_back(espinaca);
    verduras.push_back(tomate);
    verduras.push_back(cebolla);
    verduras.push_back(lechuga);
    verduras.push_back(pimiento);
    verduras.push_back(calabaza);
    verduras.push_back(coliflor);




//---------------------------------------

    cout << "Bienvenido a la aplicacion de dieta" << endl;
    cout << "Ya esta registrado en la plataforma?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    int opcion;
    cin >> opcion;
    //Check if the user is already registered
    //If not, register the user


    
    if(opcion == 1){ 
        cout << "Ingrese su nombre" << endl;
        string nombre;
        cin >> nombre;
        cout << "Ingrese su peso" << endl;
        int peso;
        cin >> peso;
        cout << "Ingrese su altura" << endl;
        int altura;
        cin >> altura;
        Usuario usuario(nombre, peso, altura);
        usuarios.push_back(usuario); //Add the user to the vector of users
    }
    else if(opcion == 2){
        cout << "Cual es su nombre" << endl;
        string nombre;
        cin >> nombre;
        //Check if name is in the vector of users
        //If not, register the user
        for(int i = 0; i < usuarios.size(); i++){
            if(usuarios[i].getNombre() == nombre){
                cout << "Bienvenido" << nombre << endl;
            }
            else{
                cout << "No esta registrado en la plataforma" << endl;
                cout << "Por favor ingrese su peso" << endl;
                int peso;
                cin >> peso;
                cout << "Ingrese su altura" << endl;
                int altura;
                cin >> altura;
                Usuario usuario(nombre, peso, altura);
                usuarios.push_back(usuario); //Add the user to the vector of users
            }

            cout << "Que desearia hacer" << endl;
            cout << "1. Generar un menu manualmente" << endl;
            cout << "2. Generar un menu automaticamente en base a calorias" << endl;
            cout << "3. Generar un menu automaticamente en base a proteinas" << endl;
            cout << "4. Salir" << endl;
            int opcion2;
            cin >> opcion2;
            if(opcion2 == 1){
                cout << "Que tipo de ingrediente desea agregar?" << endl;
                cout << "1. Fruta" << endl;
                cout << "2. Grano" << endl;
                cout << "3. Lacteo" << endl;
                cout << "4. Proteina" << endl;
                cout << "5. Verdura" << endl;
                int opcion3;
                cin >> opcion3;
                if(opcion3 == 1){
                    cout << "Que fruta desea agregar?" << endl;
                    for(int i = 0; i < frutas.size(); i++){
                        cout << i << ". " << frutas[i] << endl;
                    }
                    int opcion4;
                    cin >> opcion4;
                    usuario.addFruta(frutas[opcion4]);
                }
                else if(opcion3 == 2){
                    cout << "Que grano desea agregar?" << endl;
                    for(int i = 0; i < granos.size(); i++){
                        cout << i << ". " << granos[i] << endl;
                    }
                    int opcion4;
                    cin >> opcion4;
                    usuario.addGrano(granos[opcion4]);
                }
                else if(opcion3 == 3){
                    cout << "Que lacteo desea agregar?" << endl;
                    for(int i = 0; i < lacteos.size(); i++){
                        cout << i << ". " << lacteos[i] << endl;
                    }
                    int opcion4;
                    cin >> opcion4;
                    usuario.addLacteo(lacteos[opcion4]);
                }
                else if(opcion3 == 4){
                    cout << "Que proteina desea agregar?" << endl;
                    for(int i = 0; i < proteinas.size(); i++){
                        cout << i << ". " << proteinas[i] << endl;
                    }
                    int opcion4;
                    cin >> opcion4;
                    usuario.addProteina(proteinas[opcion4]);
                }
                else if(opcion3 == 5){
                    cout << "Que verdura desea agregar?" << endl;
                    for(int i = 0; i < verduras.size(); i++){
                        cout << i << ". " << verduras[i] << endl;
                    }
                    int opcion4;
                    cin >> opcion4;
                    usuario.addVerdura(verduras[opcion4]);
                }
                else{
                    cout << "Opcion invalida" << endl;
                }
                
                

            
        }
    }
    else{
        cout << "Opcion invalida" << endl;
    }
    







    return 0;
}
