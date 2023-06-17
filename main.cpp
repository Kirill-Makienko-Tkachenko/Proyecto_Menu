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

// Todo

// Hacer menu que calcule en base a calorias
// Hacer menu que calcule en base a carbohidratos
// Hacer menu que calcule en base a grasas
// Hacer algoritmo de calculo de calorias
// Hacer algoritmo de calculo de carbohidratos
// Hacer algoritmo de calculo de grasas

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Usuario.h"
#include "Dieta.h"
#include "Menu.h"

using namespace std;

// function to register a user

// Function to search the position of a user by name

// function to search for a user by name

Usuario registerUser(vector<Usuario> usuarios)
{
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
    return usuario;
}

int searchUserPosition(const vector<Usuario> &usuarios, const string &name)
{
    for (int i = 0; i < usuarios.size(); i++)
    {
        if (usuarios[i].getNombre() == name)
        {
            return i;
        }
    }
    return -1;
}

bool searchUser(const vector<Usuario> &usuarios, const string &name)
{
    for (const auto &usuario : usuarios)
    {
        if (usuario.getNombre() == name)
        {
            return true;
        }
    }
    return false;
}

// function to handle menu generation options

int main()
{

    Menu M1;
    vector<Usuario> usuarios;

    // Create a vector of users

    Usuario usuario1("Kirill", 100, 1.80);
    usuarios.push_back(usuario1);
    //-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
    // a REALLY STUPID RANT, FEEL FREE TO DONT READ
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

    BUSQUENLA, DONDE QUIERA QUE SERA  BUUUSENLAAAAA, QUE MI VIDA SE ACABA Y EL ANTIDOTO ES ELLA BUUUUUUSSSSQUENNNNLAAAAAAAAAAAAAAAAAAAAAAAAAA

    Algo de lo que mes estoy dando cuenta es que a cpp le ENCANTA inventarse errores, estras trabajando bien agusto y de la nada estornudas y te pone que el cout << es demasiado ambiguo y te salen 87 errores,
    pero es cuestion de reinicar el visual y magicamente todos los problemas desaparecen

    A WEBOOOOOO YA FUNCIONAAAAAAAAAAA PUTOSSSSSSSSSSSSSSSSSSSSSSSSSS CULIKITAKATI, KULIKITAKATA, CULIKITAKATI, KULIKITAKATA. SAKALAKATIKI SAKATIKI SAKALAKATIKI SAKATIKI

    Няма да се караме, няма да се биеме
    Вечер като лягаме, колело ще караме
    Няма да се караме, няма да се биеме
    Вечер като лягаме, колело ще караме
    Комбайна вършачка паламанде1 трошачка
    Комбайна вършачка паламанде трошачка
    й ще свири, драги гости само за вас
    На китарата Васко Жабата,
    Той ще свири, драги гости само за вас
    Ще чуете мелодии, хора, народни песни
    Цигански кючеци, всичките са лесни
    Ще чуете мелодии, хора, народни песни
    Цигански кючеци, всичките са лесни
    На микрофона Цеца Мецата
    Тя ще пее драги гости само за вас
    На микрофона Цеца Мецата
    Тя ще пее драги гости само за вас
    Ще чуете мелодии, хора, народни песни
    Цигански кючеци, всичките са лесни
    Ще чуете мелодии, хора, народни песни
    Цигански кючеци, всичките са лесни



    */
    //-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

    cout << "Bienvenido a la aplicacion de dietas" << endl;
    cout << "Ya esta registrado?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    int respuesta;
    cin >> respuesta;

    bool exitMenu = false;
    do
    {
        switch (respuesta)
        {
        case 1:
        {
            cout << "Ingrese su nombre de usuario" << endl;
            string nombre;
            cin >> nombre;

            bool userFound = searchUser(usuarios, nombre);
            if (userFound)
            {
                int position = searchUserPosition(usuarios, nombre);
                cout << "Bienvenido " << nombre << endl;
                cout << position << endl;
                M1.handleMenuGeneration(position, usuarios);
            }
            else
            {
                cout << "Usuario no encontrado. Por favor, registrese." << endl;
                respuesta = 2;
            }
            exitMenu = true; // Set exit condition to end the loop
            break;
        }
        case 2:
        {
            {
                string name;
                int weight;
                float height;

                cout << "Ingrese su nombre: ";
                cin >> name;
                cout << "Ingrese su peso: ";
                cin >> weight;
                cout << "Ingrese su altura: ";
                cin >> height;

                Usuario new_usuario(name, weight, height);
                usuarios.push_back(new_usuario);
                respuesta = 1;
            }
            break;
        }
        }
    } while (!exitMenu);
    return 0;
}
