#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    std::cout << "=== TEST DU SUJET ===" << std::endl;
    
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;
    
    std::cout << "\n=== TESTS SUPPLEMENTAIRES ===" << std::endl;
    
    // Test copie profonde
    std::cout << "\n--- Test copie profonde ---" << std::endl;
    Character alice("Alice");
    alice.equip(new Ice());
    alice.equip(new Cure());
    
    Character alice_copy(alice);  // Copie
    Character charlie("Charlie");
    alice_copy.use(0, charlie);
    alice_copy.use(1, charlie);
    
    // Test inventaire plein
    std::cout << "\n--- Test inventaire plein ---" << std::endl;
    Character dave("Dave");
    dave.equip(new Ice());
    dave.equip(new Cure());
    dave.equip(new Ice());
    dave.equip(new Cure());
    dave.equip(new Ice());  // Devrait être ignoré (inventaire plein)
    
    // Test unequip
    std::cout << "\n--- Test unequip ---" << std::endl;
    AMateria* saved = new Ice();
    dave.equip(saved);
    dave.unequip(0);  // Retire mais ne delete pas
    dave.use(0, charlie);  // Devrait ne rien faire
    delete saved;  // On delete manuellement
    
    // Test materia inconnue
    std::cout << "\n--- Test materia inconnue ---" << std::endl;
    MateriaSource src2;
    src2.learnMateria(new Ice());
    AMateria* unknown = src2.createMateria("fire");  // Type inconnu
    if (unknown == NULL)
        std::cout << "Materia 'fire' inconnue (normal)" << std::endl;
    
    return 0;
}
