# ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{

	private:
	Brain *brain;

	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat &copy);
		~Cat();
		Cat &operator=(const Cat &other);
		void makeSound()const;
};

#endif
