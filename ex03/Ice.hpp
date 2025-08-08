# ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICE : public AMateria
{
    private:
    Ice();
    Ice(const Ice &copy);
    ~Ice();
    Ice &operator=(const Ice &c);
    AMateria *Ice::Clone();
    Ice::Use(ICharacter& target);
};

#endif
