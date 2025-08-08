#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Dog Parameter Constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;

}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignement operator called" << std::endl;
	if (this == &other)
		return (*this);
	Animal::operator=(other);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "ouaf ouaf ouaf" <<std::endl;
}
