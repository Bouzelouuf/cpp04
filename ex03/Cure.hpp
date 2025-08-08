# ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "ICharacter.hpp"

class Cure : public AMateria
{
    private:
    Cure();
    Cure(const Cure &copy);
    ~Cure();
    Cure &operator=(const Cure &c);
    AMateria *Cure::Clone();
    Cure::Use(ICharacter& target);
};

#endif