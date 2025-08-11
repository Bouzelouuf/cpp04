#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{

   std::cout << "=== TEST SUJET EX01 ===" << std::endl;
    
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;
    delete i;
    
    std::cout << "\n=== TEST ARRAY ===" << std::endl;
    
    Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();
    
    for(int k = 0; k < 4; k++)
    {
        delete animals[k];
    }
    
    std::cout << "\n=== TEST COPIE PROFONDE ===" << std::endl;
    
    Dog basic;
    {
        Dog tmp = basic;
    }
    
    return 0;
}
