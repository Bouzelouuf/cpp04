#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy.templates[i])
			templates[i] = copy.templates[i]->clone();
		else
			templates[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (templates[i])
			delete templates[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (templates[i])
				delete templates[i];
			if (other.templates[i])
				templates[i] = other.templates[i]->clone();
			else
				templates[i] = NULL;
		}
	}
	return (*this);
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	if (type.empty())
		return (NULL);
	for (int i = 0; i < 4; i++)
	{
		if (templates[i] != NULL && templates[i]->getType() == type)
		{
			return (templates[i]->clone());
		}
	}
	return (NULL);
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (m == NULL)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (templates[i] != NULL && templates[i]->getType() == m->getType())
		{
			delete (m);
			return;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (templates[i] == NULL)
		{
			templates[i] = m->clone();
			delete m;
			return ;
		}
	}
	delete m;
}
