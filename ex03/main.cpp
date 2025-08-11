// #include "IMateriaSource.hpp"
// #include "MateriaSource.hpp"
// #include "ICharacter.hpp"
// #include "Character.hpp"
// #include "AMateria.hpp"
// #include "Ice.hpp"
// #include "Cure.hpp"

// int main()
// {
// IMateriaSource* src = new MateriaSource();
// src->learnMateria(new Ice());
// src->learnMateria(new Cure());
// ICharacter* me = new Character("me");
// AMateria* tmp;
// tmp = src->createMateria("ice");
// me->equip(tmp);
// tmp = src->createMateria("cure");
// me->equip(tmp);
// ICharacter* bob = new Character("bob");
// me->use(0, *bob);
// me->use(1, *bob);
// delete bob;
// delete me;
// delete src;
// return 0;

// }


#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    std::cout << "=== TEST 1: BASIC FUNCTIONALITY (du sujet) ===" << std::endl;
    {
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
    }

    std::cout << "\n=== TEST 2: CHARACTER DEEP COPY ===" << std::endl;
    {
        std::cout << "Création character1 avec materias:" << std::endl;
        Character* char1 = new Character("Alice");
        char1->equip(new Ice());
        char1->equip(new Cure());
        
        std::cout << "\nCopie character1 -> character2:" << std::endl;
        Character* char2 = new Character(*char1);
        
        std::cout << "\nTest avant suppression char1:" << std::endl;
        Character bob("Bob");
        char1->use(0, bob);
        char2->use(0, bob);
        
        std::cout << "\nSuppression char1 (char2 doit rester intact):" << std::endl;
        delete char1;
        
        std::cout << "Test char2 après suppression char1:" << std::endl;
        char2->use(0, bob);
        char2->use(1, bob);
        
        delete char2;
    }

    std::cout << "\n=== TEST 3: CHARACTER ASSIGNMENT OPERATOR ===" << std::endl;
    {
        Character char1("Alice");
        Character char2("Bob");
        
        char1.equip(new Ice());
        char1.equip(new Cure());
        char2.equip(new Ice());
        
        std::cout << "Avant assignation:" << std::endl;
        Character target("Target");
        char1.use(0, target);
        char2.use(0, target);
        
        std::cout << "\nAssignation char2 = char1:" << std::endl;
        char2 = char1;
        
        std::cout << "Après assignation:" << std::endl;
        char2.use(0, target);
        char2.use(1, target);
    }

    std::cout << "\n=== TEST 4: MATERIASOURCE DEEP COPY ===" << std::endl;
    {
        MateriaSource* src1 = new MateriaSource();
        src1->learnMateria(new Ice());
        src1->learnMateria(new Cure());
        
        std::cout << "Copie src1 -> src2:" << std::endl;
        MateriaSource* src2 = new MateriaSource(*src1);
        
        std::cout << "Test création après copie:" << std::endl;
        AMateria* ice1 = src1->createMateria("ice");
        AMateria* ice2 = src2->createMateria("ice");
        
        if(ice1 && ice2) {
            Character test("Test");
            ice1->use(test);
            ice2->use(test);
            delete ice1;
            delete ice2;
        }
        
        delete src1;
        delete src2;
    }

    std::cout << "\n=== TEST 5: CAS LIMITES ===" << std::endl;
    {
        Character char1("Test");
        
        std::cout << "Test inventaire plein (5 materias):" << std::endl;
        char1.equip(new Ice());
        char1.equip(new Cure());
        char1.equip(new Ice());
        char1.equip(new Cure());
        char1.equip(new Ice());


        std::cout << "Test index invalides:" << std::endl;
        Character target("Target");
        char1.use(-1, target);
        char1.use(4, target);
        char1.use(10, target);
        
        std::cout << "Test unequip:" << std::endl;

		AMateria *spellIce = char1.getMateria(0);
		char1.unequip(0);
		delete (spellIce);
        char1.use(0, target);
        std::cout << "Test unequip index invalide:" << std::endl;
        char1.unequip(-1);
        char1.unequip(10);
    }

    std::cout << "\n=== TEST 6: TYPE INCONNU ===" << std::endl;
    {
        MateriaSource src;
        src.learnMateria(new Ice());
        
        AMateria* unknown = src.createMateria("fire");  // Type inexistant
        if(unknown == NULL) {
            std::cout << "createMateria('fire') retourne NULL ✅" << std::endl;
        } else {
            std::cout << "createMateria('fire') ne retourne pas NULL ❌" << std::endl;
            delete unknown;
        }
        
        AMateria* empty = src.createMateria("");
        if(empty == NULL) {
            std::cout << "createMateria('') retourne NULL ✅" << std::endl;
        } else {
            std::cout << "createMateria('') ne retourne pas NULL ❌" << std::endl;
            delete empty;
        }
    }

    std::cout << "\n=== TEST 7: MATERIASOURCE PLEINE ===" << std::endl;
    {
        MateriaSource src;
        
        std::cout << "Apprentissage 5 materias (max 4):" << std::endl;
        src.learnMateria(new Ice());
        src.learnMateria(new Cure());
        src.learnMateria(new Ice());
        src.learnMateria(new Cure());
        src.learnMateria(new Ice());
    }

    std::cout << "\n=== TEST 8: GESTION MÉMOIRE UNEQUIP ===" << std::endl;
    {
        Character* char1 = new Character("Alice");
        char1->equip(new Ice());
        AMateria *spellIce = char1->getMateria(0);
        std::cout << "Unequip sans récupération (que devient la Materia?):" << std::endl;
        char1->unequip(0);  // Où va la Materia?
        delete(spellIce);
        delete char1;
        // Y a-t-il un leak de la Materia unequip?
    }

    return 0;
}
