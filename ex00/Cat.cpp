#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Cat Parameter Constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;

}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignement operator called" << std::endl;
	if (this == &other)
		return (*this);
	Animal::operator=(other);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "miaou miaou miaou" <<std::endl;
}
