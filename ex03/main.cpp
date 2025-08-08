#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    // Test que AAnimal ne peut pas être instanciée
    // AAnimal animal; // Erreur de compilation !
    
    const AAnimal* dog = new Dog();
    const AAnimal* cat = new Cat();
    
    dog->makeSound();
    cat->makeSound();
    
    delete dog;
    delete cat;
    
    return 0;
}