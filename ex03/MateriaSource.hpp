#ifndef MATERIASOURCE
#define MATERIASOURCE
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    private:
    AMateria *templates[4];
    public:
    MateriaSource();
    ~MateriaSource();
    void learnMateria(AMateria *m);
    AMateria* createMateria(std::string const& type);
};

AMateria* MateriaSource::createMateria(std::string const& type)
{
    if (type.empty())
        return (NULL);
    for (int i = 0; i < 4; i++)
    {
        if (templates[i] != NULL && templates[i]->getType() == type)
        {
            return(templates[i]->clone());
        }
    }
    return (NULL);
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (m == NULL)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (templates[i] == NULL)
        {
            templates[i] = m->clone();
            return;
        }
    }
}
#endif
