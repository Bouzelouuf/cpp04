# ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	private:
	Brain *brain;

	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog &copy);
		~Dog();
		Dog &operator=(const Dog &other);
		void makeSound() const; // override que pour c++11
};

#endif
