#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : type("default")
{
}

AMateria::AMateria(const std::string &type) : type(type)
{
}

AMateria::AMateria(const AMateria &copy) : type(copy.type)
{
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator=(const AMateria &other)
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}
std::string const & AMateria::getType() const
{

    return(this->type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* uses some materia on " << target.getName() << " *" << std::endl;
}
