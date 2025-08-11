#include "Animal.hpp"

Animal::Animal() : type("undefined")
{
	std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal parameter constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) : type (copy.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}
Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}


Animal& Animal::operator=(const Animal &other)
{
	std::cout	<< "Animal assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

std::string Animal::getType() const
{
	return(type);
}

void Animal::makeSound() const
{
	std::cout << "Animal make no sound" <<std::endl;
}
