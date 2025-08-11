#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== POLYMORPHISM TEST ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    
    delete meta;
    delete j;
    delete i;
    
    std::cout << "\n=== WRONG CLASSES (NO POLYMORPHISM) ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    wrongMeta->makeSound();
    wrongCat->makeSound(); // should make wronganimal sound
    
    delete wrongMeta;
    delete wrongCat;
    
    std::cout << "\n=== ARRAY TEST ===" << std::endl;
    Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();
    
    for(int k = 0; k < 4; k++)
    {
        animals[k]->makeSound();
        delete animals[k];
    }
    
    return 0;
}
