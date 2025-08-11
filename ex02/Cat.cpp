#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat") , brain(new Brain()) 
{
	std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::Cat(std::string type) : AAnimal(type), brain(new Brain()) 
{
	std::cout << "Cat Parameter Constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : AAnimal(copy)
{
	brain = new Brain(*copy.brain);
	std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat::~Cat()
{
	delete(brain);
	std::cout << "Cat Destructor called" << std::endl;

}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignement operator called" << std::endl;
	if (this == &other)
		return (*this);
	AAnimal::operator=(other);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "miaou miaou miaou" <<std::endl;
}
