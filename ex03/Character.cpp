void Character::equip(AMateria* m)
{
    if (m == NULL)
        return;
    for (int i = 0; i < 4 ; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx <= 3 && inventory[idx] != NULL)
        inventory[idx] = NULL;
}       

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && <= 3 && inventory[idx] != NULL)
        inventory[idx]->use(target);
}

std::string const & Character::getName() const
{
    return this->name;
}

Character::Character(std::string const &name) :name(name)
{
}