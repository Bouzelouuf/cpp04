AMateria::AMateria() : type("default")
{
}

AMateria::AMateria(std::string &type) : type(type)
{
}

AMateria::AMateria(std::string &copy) : type(copy.type)
{
}

AMateria::~AMateria()
{
}

AMateria(std::string const & type) : type(type)
{
    //this->type = type;
}

AMateria::AMateria &operator=(const AMateria &other)
{
    if (*this != &other)
        this->type = other.type;
    return (*this);
}
std::string const & AMateria::getType() const
{
    if (!this->type.empty())
        return(type);
    else
    {
        std::cout<< "no type" std::endl; 
        return(this->type);
    }
}

void AMateria::use(ICharacter& target)
{
    std::cout<< "* heals " target " 's wounds*" << std::endl;
}