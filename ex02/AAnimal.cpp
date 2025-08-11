#include "AAnimal.hpp"

AAnimal::AAnimal() : type("undefined")
{
	std::cout << "AAnimal Default Constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type)
{
	std::cout << "AAnimal parameter constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) : type(copy.type)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
}
AAnimal::~AAnimal()
{
	std::cout << "AAnimal Destructor called" << std::endl;
}


AAnimal& AAnimal::operator=(const AAnimal &other)
{
	std::cout	<< "AAnimal assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

std::string AAnimal::getType() const
{
	return(type);
}

// void AAnimal::makeSound() const
// {
// 	std::cout << "AAnimal make no sound" <<std::endl;
// }
