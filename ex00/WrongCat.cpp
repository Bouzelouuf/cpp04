#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Default Constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << "WrongCat Parameter Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat Copy Constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;

}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat assignement operator called" << std::endl;
	if (this == &other)
		return (*this);
	WrongAnimal::operator=(other);
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "miaou miaou miaou" <<std::endl;
}
