#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
    std::cout << "=== TEST 1: POLYMORPHISME AVEC CLASSES ABSTRAITES ===" << std::endl;
    {
        AAnimal* dog = new Dog();
        AAnimal* cat = new Cat();
        
        std::cout << "Types: " << dog->getType() << ", " << cat->getType() << std::endl;
        dog->makeSound();
        cat->makeSound();
        
        delete dog;
        delete cat;
    }
    
    std::cout << "\n=== TEST 2: COPIE PROFONDE AVEC OBJETS (stack) ===" << std::endl;
    {
        std::cout << "Création cat1:" << std::endl;
        Cat cat1;
        
        std::cout << "\nCopie cat1 -> cat2:" << std::endl;
        Cat cat2 = cat1;
        
        std::cout << "\nTest sons (doivent être identiques):" << std::endl;
        cat1.makeSound();
        cat2.makeSound();
        
        std::cout << "\nDestruction automatique:" << std::endl;
    }
    
    std::cout << "\n=== TEST 3: COPIE PROFONDE AVEC POINTEURS ===" << std::endl;
    {
        Cat* cat1 = new Cat();
        Cat* cat2 = new Cat(*cat1);
        
        std::cout << "Sons avant suppression cat1:" << std::endl;
        cat1->makeSound();
        cat2->makeSound();
        
        std::cout << "\nSuppression cat1 (cat2 doit rester intact):" << std::endl;
        delete cat1;
        
        std::cout << "Son de cat2 après suppression cat1:" << std::endl;
        cat2->makeSound();
        
        delete cat2;
    }
    
    std::cout << "\n=== TEST 4: OPÉRATEUR D'ASSIGNATION ===" << std::endl;
    {
        Cat cat1;
        Cat cat2;
        
        std::cout << "Avant assignation:" << std::endl;
        cat1.makeSound();
        cat2.makeSound();
        
        std::cout << "\nAssignation cat1 = cat2:" << std::endl;
        cat1 = cat2;
        
        std::cout << "Après assignation:" << std::endl;
        cat1.makeSound();
        cat2.makeSound();
    }
    
    std::cout << "\n=== TEST 5: ARRAY D'ANIMAUX (comme demandé dans le sujet) ===" << std::endl;
    {
        const int size = 6;
        AAnimal* animals[size];
        
        for(int i = 0; i < size; i++) {
            if(i < size/2)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }
        
        std::cout << "\nTous les animaux font du bruit:" << std::endl;
        for(int i = 0; i < size; i++) {
            std::cout << i << ": ";
            animals[i]->makeSound();
        }
        
        std::cout << "\nDestruction du tableau:" << std::endl;
        for(int i = 0; i < size; i++) {
            delete animals[i];
        }
    }
    
    std::cout << "\n=== TEST 6: TENTATIVE D'INSTANCIATION ABSTRAITE (doit pas compiler) ===" << std::endl;
    // AAnimal abstract;  // decomment pour voir
    std::cout << "AAnimal ne peut pas être instanciée (test désactivé)" << std::endl;
    
    return 0;
}
