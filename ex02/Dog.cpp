#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog") , brain(new Brain())
{
	std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(std::string type) : AAnimal(type) , brain(new Brain())
{
	std::cout << "Dog Parameter Constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : AAnimal(copy)
{
	brain = new Brain(*copy.brain);
	std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog::~Dog()
{
	delete(brain);
	std::cout << "Dog Destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignement operator called" << std::endl;
	if (this == &other)
		return (*this);
	AAnimal::operator=(other);
	delete brain;
    brain = new Brain(*other.brain);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "ouaf ouaf ouaf" <<std::endl;
}
