Ice::Ice(void): AMateria("Ice")
{
	std::cout << "Ice created with default constructor" << std::endl;
}

Ice::~Ice(void)
{
	std::cout << "Ice destroyed" << std::endl;
}

Ice::Ice(Ice const &copy): AMateria(copy)
{
	std::cout << "Ice copied" << std::endl;
}

Ice const	&Ice::operator=(const Ice &copy)
{
	this->_type = copy._type;
	return (*this);
}

AMateria *Ice::Clone() const
{
    return (new Ice(*this));
}

void Ice::Use(ICharacter& target)
{
    std::cout<< "* heals " target.name " 's wounds*" << std::endl;
}
