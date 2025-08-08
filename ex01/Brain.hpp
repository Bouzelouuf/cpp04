#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
	std::string ideas [100];

	public:
	Brain();
	Brain(std::string type);
	Brain(const Brain &copy);
	Brain &operator=(const Brain &other);
	virtual ~Brain();
};

#endif
