Cure::Cure(void): AMateria("cure")
{
	std::cout << "Cure created with default constructor" << std::endl;
}

Cure::~Cure(void)
{
	std::cout << "Cure destroyed" << std::endl;
}

Cure::Cure(Cure const &copy): AMateria(copy)
{
	std::cout << "Cure copied" << std::endl;
}

Cure const	&Cure::operator=(const Cure &copy)
{
	this->_type = copy._type;
	return (*this);
}

AMateria *Cure::Clone() const
{
    return (new Cure(*this));
}

void Cure::Use(ICharacter& target)
{
    std::cout<< "* heals " target.name " 's wounds*" << std::endl;
}