# ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{

	private:
	Brain *brain;

	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat &copy);
		~Cat();
		Cat &operator=(const Cat &other);
		void makeSound()const ; // override que pour c++11
};

#endif
