#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure created with default constructor" << std::endl;
}

Cure::~Cure(void)
{
	std::cout << "Cure destroyed" << std::endl;
}

Cure::Cure(Cure const &copy) : AMateria(copy)
{
	std::cout << "Cure copied" << std::endl;
}
Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
