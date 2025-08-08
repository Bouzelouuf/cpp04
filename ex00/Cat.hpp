# ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat &copy);
		~Cat();
		Cat &operator=(const Cat &other);
		void makeSound()const;
};

#endif
