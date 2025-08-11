#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal("Dog") , brain(new Brain())
{
	std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) , brain(new Brain())
{
	std::cout << "Dog Parameter Constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	brain = new Brain(*copy.brain);
	std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog Destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignement operator called" << std::endl;
	if (this == &other)
		return (*this);
	Animal::operator=(other);
	delete brain;
    brain = new Brain(*other.brain);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "ouaf ouaf ouaf" <<std::endl;
}
