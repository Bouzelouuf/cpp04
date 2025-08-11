#include "Cat.hpp"

Cat::Cat() : Animal("Cat") , brain(new Brain())
{
	std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type) , brain(new Brain())
{
	std::cout << "Cat Parameter Constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	brain = new Brain(*copy.brain);
	std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat Destructor called" << std::endl;

}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignement operator called" << std::endl;
	if (this == &other)
		return (*this);
	Animal::operator=(other);
	delete brain;
    brain = new Brain(*other.brain);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "miaou miaou miaou" <<std::endl;
}
