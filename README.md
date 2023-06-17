# Proyecto_Menu

#Main Program Algorithm

Since we have 5 ingredients intuitively we shoud devide the quantity of calories and fats and carbohydrates with the ingredients that have the most of them, I´ve decided to divide it by the most important foods of a diet, the protein is the most important food, so, depending if a diet is vegetarian or not the main course will be a protein and everything else will be add-ons, ill divide the ingredients al follows:

- Frutas - 5%
- Verduras - 10%
- Granos - 10%
- Lacteos - 10%
- Proteina - 65%

The maximum quantity of calories will depend on the BMI of the person an whether or not they are fat.

 - x>18.5 is underwheight
 - 18.5<x<24.9 is "Healthy"
 - 25<x<29.9 is "Overweight"
 - 30<x<39.9 is "Obersity"
 - x<40 is "Obesity"
(https://www.nhsinform.scot/healthy-living/food-and-nutrition/healthy-eating-and-weight-loss/body-mass-index-bmi)


#CalcularCalorias Class

There is however a bug that prevents the user from consulting the menus that they have generated because for some reason the vevctor that class Dieta returns is empty, I have tried to fix it but I have not been able to do so, I have tried to fix it by changing the way the vector is returned, and nothing works and now im out of time to try to correct it


    The class has the following private member variables:
        ingredientes: A vector of pointers to Ingrediente objects. It stores the ingredients used for calculating calories.
        calorias: An integer representing the total calories calculated from the ingredients.

    Public member functions:
        agregarIngrediente(Ingrediente* ingrediente): This function takes a pointer to an Ingrediente object and adds it to the ingredientes vector.
        agregarIngredientes(const std::vector<Ingrediente*>& ingredientesVector): This function takes a vector of pointers to Ingrediente objects and adds them to the ingredientes vector.
        calcularTotalCalorias() const: This function calculates the total calories by summing up the calories of all the ingredients in the ingredientes vector. It returns the total calories as an integer.
        calcularTotalCarbohidratos() const: This function calculates the total amount of carbohydrates by summing up the carbohydrates of all the ingredients in the ingredientes vector. It returns the total carbohydrates as an integer.
        calcularTotalGrasas() const: This function calculates the total amount of fats by summing up the fats of all the ingredients in the ingredientes vector. It returns the total fats as an integer.

    Overloaded operator<<:
        This friend function overloads the << operator to provide a convenient way to print the CalcularCalorias object. It outputs the total calories, total carbohydrates, and total fats by calling the corresponding member functions of CalcularCalorias.

Overall, the CalcularCalorias class is responsible for aggregating ingredients, calculating the total calories, total carbohydrates, and total fats based on the provided ingredients, and providing a printable representation of the calculated values.

#Dieta

    The class has the following private member variables:
        calorias: An integer representing the total calories of the diet. It is initialized to 500 by default but can be set using the parameterized constructor.
        ingredientes: A vector of pointers to Ingrediente objects. It stores the selected ingredients for the diet.
        perFrutas, perVerduras, perGranos, perLacteos, perProteina: These variables represent the percentages of calories allocated to different food groups in the diet.
        caloriasFrutas, caloriasVerduras, caloriasGranos, caloriasLacteos, caloriasProteina: These variables store the calculated calories for each food group based on the specified percentages.
        frutas, verduras, granos, lacteos, proteinas: These vectors store the available options for each food group (Frutas, Verdura, Granos, Lacteos, Proteina).

    Public member functions:
        Dieta(): Default constructor that initializes the calorias variable to 500.
        Dieta(int calorias): Parameterized constructor that allows setting the calorias variable to a specific value.
        calcularCaloriasDieta(): This function calculates the calorie distribution for each food group based on the specified percentages (perFrutas, perVerduras, perGranos, perLacteos, perProteina).
        calcularDieta(): This function calculates the actual diet by randomly selecting ingredients from each food group according to the calculated calorie distribution. It modifies the gramaje (gram weight) of each ingredient to fit the allocated calories. The modified ingredients are added to the ingredientes vector.
        getRandNum(const int& min, const int& max): This function generates a random number between the given minimum and maximum values.

    Getters and setters: The class provides getter and setter methods for accessing and modifying the private member variables.

Overall, the Dieta class is responsible for generating a diet plan by allocating calories to different food groups based on predefined percentages, randomly selecting ingredients from each food group, and adjusting the gram weight of the ingredients to fit the allocated calories. The calculated diet is stored in the ingredientes vector, which can be accessed and modified using the provided getter and setter methods.

#Ingrediente

    The class has the following private member variables:
        nombre: A string representing the name of the ingredient.
        tipoIngrediente: A string representing the type of ingredient.
        calorias, carbohidratos, grasas: Integers representing the calorie, carbohydrate, and fat content of the ingredient, respectively.
        gramos: An integer representing the gram weight of the ingredient.

    Constructors:
        Ingrediente(string nombre, string tipoIngrediente, int calorias, int carbohidratos, int grasas, int gramos): An inline constructor that allows initializing all member variables at the time of object creation.
        Ingrediente() = default;: A default constructor that takes no arguments and initializes the member variables with default values.

    Getter and setter methods:
        Getter methods (getNombre(), getTipoIngrediente(), getCalorias(), getCarbohidratos(), getGrasas(), getGramaje()) are provided to access the private member variables.
        Setter methods (setNombre(), setTipoIngrediente(), setCalorias(), setCarbohidratos(), setGrasas(), setGramaje()) are provided to modify the private member variables.

    Other member functions:
        printIngredient(): This function prints the details of the ingredient, including its name, type, calories, carbohydrates, and fats.

    Overloaded operators:
        operator<<(): The << operator is overloaded to allow streaming the ingredient object to an output stream, such as cout. It prints the details of the ingredient in a formatted manner.

The Ingrediente class represents an individual ingredient with its nutritional information. It provides methods to access and modify the ingredient's properties and allows printing the ingredient's details.

#Fruta
    The Frutas class is derived from the base class Ingrediente, indicating that it inherits the properties and methods of the Ingrediente class.

    The class introduces an additional private member variable:
        azucar: An integer representing the sugar content of the fruit.

    Constructors:
        The class provides a default constructor (Frutas()) and a parameterized constructor (Frutas(string nombre, string tipoIngrediente, int calorias, int carbohidratos, int grasas, int gramos, int azucar)) to initialize the member variables of the class. The parameterized constructor calls the base class constructor (Ingrediente) to initialize common properties and sets the azucar value.

    Getter and setter methods:
        The class provides a getter method (getAzucar()) to access the private azucar member variable.
        A setter method (setAzucar()) is provided to modify the azucar value.

    Other member functions:
        printFruit(): This method prints the details of the fruit, including its name, type, calories, carbohydrates, fats, and sugar content.

    Overloaded operators:
        operator<<(): The << operator is overloaded to allow streaming the Frutas object to an output stream, such as cout. It prints the details of the fruit, including its name, type, calories, carbohydrates, fats, and sugar content, in a formatted manner.

The Frutas class extends the functionality of the base class Ingrediente by introducing the sugar content specific to fruits. It provides methods to access and modify the sugar content and allows printing the details of a fruit.

#Granos

    The Granos class is derived from the base class Ingrediente, indicating that it inherits the properties and methods of the Ingrediente class.

    The class introduces additional private member variables:
        proteinas: An integer representing the protein content of the grain.
        sodio: An integer representing the sodium content of the grain.
        isIntegral: A boolean value indicating whether the grain is whole grain or not.

    Constructors:
        The class provides a default constructor (Granos()) and a parameterized constructor (Granos(string nombre, string tipoIngrediente, int calorias, int carbohidratos, int grasas, int gramos, int proteinas, int sodio, bool isIntegral)) to initialize the member variables of the class. The parameterized constructor calls the base class constructor (Ingrediente) to initialize common properties and sets the additional properties specific to grains.

    Getter and setter methods:
        The class provides getter methods (getProteinas(), getSodio(), getIsIntegral()) to access the private member variables.
        Setter methods (setProteinas(), setSodio(), setIsIntegral()) are provided to modify the respective member variables.

    Other member functions:
        printGrain(): This method prints the details of the grain, including its name, type, calories, carbohydrates, fats, protein content, sodium content, and whether it is whole grain or not.

    Overloaded operators:
        operator<<(): The << operator is overloaded to allow streaming the Granos object to an output stream, such as cout. It prints the details of the grain, including its name, type, calories, carbohydrates, fats, protein content, sodium content, and whether it is whole grain or not, in a formatted manner.

The Granos class extends the functionality of the base class Ingrediente by introducing properties specific to grains, such as protein content, sodium content, and whether it is whole grain or not. It provides methods to access and modify these properties and allows printing the details of a grain.

#Lacteos

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

class Lacteos : public Ingrediente {
private:
    int grasasSaturadas;
    int proteinas;
    int colesterol;

public:
    // Default constructor
    Lacteos() {}

    // Parameterized constructor
    Lacteos(std::string nombre, std::string tipoIngrediente, int calorias, int carbohidratos, int grasas, int gramos,
            int grasasSaturadas, int proteinas, int colesterol)
        : Ingrediente(nombre, tipoIngrediente, calorias, carbohidratos, grasas, gramos),
          grasasSaturadas(grasasSaturadas), proteinas(proteinas), colesterol(colesterol) {}

    // Setters and Getters
    void setGrasasSaturadas(int grasasSaturadas) { this->grasasSaturadas = grasasSaturadas; }
    const int& getGrasasSaturadas() const { return grasasSaturadas; }

    void setProteinas(int proteinas) { this->proteinas = proteinas; }
    const int& getProteinas() { return proteinas; }

    void setColesterol(int colesterol) { this->colesterol = colesterol; }
    const int& getColesterol() { return colesterol; }

    // Method to print dairy details
    void printDairy() {
        std::cout << "Nombre: " << getNombre() << std::endl;
        std::cout << "Tipo de Ingrediente: " << getTipoIngrediente() << std::endl;
        std::cout << "Calorías: " << getCalorias() << std::endl;
        std::cout << "Carbohidratos: " << getCarbohidratos() << std::endl;
        std::cout << "Grasas: " << getGrasas() << std::endl;
        std::cout << "Grasas Saturadas: " << grasasSaturadas << std::endl;
        std::cout << "Proteínas: " << proteinas << std::endl;
        std::cout << "Colesterol: " << colesterol << std::endl;
    }
};

//Overload << operator

std::ostream& operator<<(std::ostream& os, Lacteos& lacteo) {
    os << "Nombre: " << lacteo.getNombre() <<  " Tipo de Ingrediente: " << lacteo.getTipoIngrediente() << " Calorías: " << lacteo.getCalorias() << " Carbohidratos: " << lacteo.getCarbohidratos() << " Grasas: " << lacteo.getGrasas() << std::endl;
    os << " Grasas Saturadas: " << lacteo.getGrasasSaturadas() << " Proteínas: " << lacteo.getProteinas() << " Colesterol: " << lacteo.getColesterol();
    return os;
}

#Menu

    The Menu class is used to manage the menu and operations of the diet application.

    The class includes private member variables:
        frutas: A vector of Frutas objects, representing the available fruit ingredients.
        granos: A vector of Granos objects, representing the available grain ingredients.
        lacteos: A vector of Lacteos objects, representing the available dairy ingredients.
        carnes: A vector of Proteina objects, representing the available protein ingredients.
        usuarios: A vector of Usuario objects, representing the users of the application.
        vegetales: A vector of Verdura objects, representing the available vegetable ingredients.
        dietas: A vector of Dieta objects, representing the generated diets.
        calcularCalorias: A vector of CalcularCalorias objects, used for calorie calculations.
        ingredientes: A vector of Ingrediente* pointers, used to store the selected ingredients.

    Constructors:
        The class provides a default constructor (Menu()) and a parameterized constructor (Menu(vector<Frutas> frutas, vector<Granos> granos, vector<Lacteos> lacteos, vector<Proteina> proteinas, vector<Usuario> usuarios, vector<Verdura> verduras, vector<Dieta> dietas, vector<CalcularCalorias> calcularCalorias)) to initialize the member variables of the class.

    Setter and getter methods:
        The class provides setter and getter methods for each private member variable, allowing access and modification of the data stored in those variables.

    File reading methods:
        The class includes several methods (readFrutasFromFile(), readGranosFromFile(), readLacteosFromFile(), readProteinasFromFile(), readVerdurasFromFile()) to read data from specific files and populate the corresponding vectors (frutas, granos, lacteos, proteinas, verduras) with the read data.

    Menu generation and handling:
        The method handleMenuGeneration() is used to handle the menu generation process and user interactions.
        It provides a menu with different options:
            Generate a menu manually: Allows the user to select ingredients from different categories (frutas, granos, lacteos, proteinas, verduras) and add them to the ingredientes vector.
            Generate a menu automatically based on calorie requirements: Calculates the user's Body Mass Index (BMI) and recommends a calorie intake based on it. The user can enter the desired calorie intake, and a diet (Dieta) object is generated with the appropriate ingredients based on the calorie requirement.
            Review generated diets: Displays the ingredients added to the ingredientes vector and the date when the diet was created.
            Exit the program.

The Menu class acts as the central control for managing the menu generation and user interactions in the diet application. It provides methods for reading ingredient data from files, generating menus manually or automatically, and handling user input for diet management.

#Proteina

    The Proteina class represents a type of ingredient, specifically proteins, within the diet application.

    The class inherits from the Ingrediente class, which suggests that Proteina is a specialized type of ingredient.

    The class includes private member variables:
        grasasSaturadas: An integer representing the amount of saturated fat in the protein.
        proteinas: An integer representing the amount of protein in the protein.
        colesterol: An integer representing the amount of cholesterol in the protein.
        sodio: An integer representing the amount of sodium in the protein.

    Constructors:
        The class provides a default constructor (Proteina()) and a parameterized constructor (Proteina(string nombre, string tipoIngrediente, int calorias, int carbohidratos, int grasas, int gramos, int grasasSaturadas, int proteinas, int colesterol, int sodio)) to initialize the member variables of the class.

    Setter and getter methods:
        The class provides getter methods for each private member variable, allowing access to the values stored in those variables.
        The class also provides setter methods to modify the values of grasasSaturadas, proteinas, colesterol, and sodio.

    Method to print protein details:
        The class includes a method printProtein() that prints the details of the protein, including its name, type, calories, carbohydrates, fats, saturated fats, proteins, cholesterol, and sodium.

    Overloaded stream insertion operator:
        The class overloads the << operator to allow the object of the Proteina class to be directly printed using cout.
        The overloaded operator formats the protein details and streams them to the output stream.

The Proteina class represents protein ingredients within the diet application. It provides methods to access and modify the protein details and allows for printing the protein details conveniently.

#Usuario

    The Usuario class represents a user in the diet application. It stores information about the user's name, weight, height, and their diet ingredients.

    The class includes private member variables:
        nombre: A string representing the name of the user.
        peso: A double representing the weight of the user.
        altura: A double representing the height of the user.
        ingredientes: A vector of pointers to Ingrediente objects, representing the user's diet ingredients.

    Constructors:
        The class provides a default constructor (Usuario()).
        It also provides two parameterized constructors:
            Usuario(const std::string& nombre, double peso, double altura) allows setting the name, weight, and height of the user without specifying the diet ingredients.
            Usuario(const std::string& nombre, double peso, double altura, vector<Ingrediente*> ingredientes) additionally allows initializing the user's diet ingredients.

    Setter and getter methods:
        The class provides setter and getter methods for nombre, peso, and altura to modify and access the corresponding member variables.

    Method to calculate BMI:
        The class includes a method calcularBMI() that calculates the user's BMI (Body Mass Index) based on their weight and height. It returns the calculated BMI value.

    Method to print the user's name:
        The class includes a method printNombre() that prints the user's name.

    Method to manage diet ingredients:
        The class provides a method agregarIngredientes() to add a vector of Ingrediente pointers to the user's diet. The method appends the new ingredients to the existing ones.

    Getter method for the vector of diet ingredients:
        The class includes a getter method getIngredientes() that returns the vector of Ingrediente pointers representing the user's diet ingredients.

    Overloaded stream insertion operator:
        The class overloads the << operator to allow the object of the Usuario class to be directly printed using cout.
        The overloaded operator formats the user's information, including name, weight, and height, and streams them to the output stream.

The Usuario class represents a user within the diet application. It stores user information and provides methods to access and modify that information. It also manages the user's diet ingredients and allows for convenient printing of user details.

#Verdura

    The Verdura class represents a vegetable ingredient in the diet application. It is derived from the base class Ingrediente and extends it with additional properties specific to vegetables.

    The class includes private member variables:
        proteinas: An integer representing the amount of proteins in the vegetable.
        isOrganico: A boolean indicating whether the vegetable is organic or not.

    Constructors:
        The class provides a default constructor (Verdura()).
        It also provides a parameterized constructor (Verdura(std::string nombre, std::string tipoIngrediente, int calorias, int carbohidratos, int grasas, int gramos, int proteinas, bool isOrganico)) that allows initializing all the member variables of the Verdura object.

    Setters and getters:
        The class provides setter and getter methods for proteinas and isOrganico to modify and access the corresponding member variables.

    Method to print vegetable details:
        The class includes a method printVerdura() that prints the details of the vegetable, including its name, type, calories, carbohydrates, fats, proteins, and whether it is organic or not.

    Overloaded stream insertion operator:
        The class overloads the << operator to allow the object of the Verdura class to be directly printed using cout.
        The overloaded operator formats the vegetable's information, including name, type, calories, carbohydrates, fats, proteins, and organic status, and streams them to the output stream.

The Verdura class represents a vegetable ingredient within the diet application. It inherits properties and behaviors from the Ingrediente base class and extends it with specific properties related to vegetables. It provides methods to access and modify the vegetable's details and allows for convenient printing of vegetable information.