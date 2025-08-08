#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
# include "ICharacter.hpp"
# include <iostream>

class Ice : public AMateria
{
  public:
	Ice();
	Ice(const Ice &copy);
	virtual ~Ice();
	Ice &operator=(const Ice &other);
	virtual AMateria *clone()const;
	virtual void use(ICharacter &target);
};

#endif
