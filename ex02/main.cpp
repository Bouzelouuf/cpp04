#include "Brain.hpp"
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#include <iostream>

int main() {
    // Création d'objets Dog et Cat
    AAnimal* dog1 = new Dog();
    AAnimal* cat1 = new Cat();

    // Utilisation des pointeurs pour appeler makeSound
    dog1->makeSound(); // Devrait afficher "ouaf ouaf ouaf"
    cat1->makeSound(); // Devrait afficher "miaou miaou miaou"

    // Test de la copie profonde
    AAnimal* dog2 = new Dog(*dynamic_cast<Dog*>(dog1)); // Utilisation du constructeur de copie
    AAnimal* cat2 = new Cat(*dynamic_cast<Cat*>(cat1)); // Utilisation du constructeur de copie

    // Vérification des sons des objets copiés
    dog2->makeSound(); // Devrait afficher "ouaf ouaf ouaf"
    cat2->makeSound(); // Devrait afficher "miaou miaou miaou"

    // Vérification des types
    std::cout << "Dog1 type: " << dog1->getType() << std::endl; // Devrait afficher "Dog"
    std::cout << "Dog2 type: " << dog2->getType() << std::endl; // Devrait afficher "Dog"
    std::cout << "Cat1 type: " << cat1->getType() << std::endl; // Devrait afficher "Cat"
    std::cout << "Cat2 type: " << cat2->getType() << std::endl; // Devrait afficher "Cat"

    // Libération de la mémoire
    delete dog1; // Appelle le destructeur de Dog
    delete cat1; // Appelle le destructeur de Cat
    delete dog2; // Appelle le destructeur de Dog
    delete cat2; // Appelle le destructeur de Cat

    return 0;
}
