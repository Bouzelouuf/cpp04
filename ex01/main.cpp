#include "Brain.hpp"
#include <iostream>

int main()
{
    std::cout << "\n=== Test 5: Test de leak potentiel ===" << std::endl;
    {
        Brain* brain6 = new Brain();
        Brain* brain7 = new Brain(*brain6);
        // Simulation d'une copie profonde
        delete brain6;
        delete brain7;
    }

    // std::cout << "\n=== Test 3: Affectation avec pointeurs ===" << std::endl;
    // Brain* brain4 = new Brain();
    // Brain* brain5 = new Brain();
    // *brain5 = *brain4;  // Opérateur d'affectation
    // delete brain4;
    // delete brain5;
    

    // std::cout << "=== Test 1: Constructeur par défaut ===" << std::endl;
    // Brain brain1;
    
    // std::cout << "\n=== Test 2: Constructeur de copie ===" << std::endl;
    // Brain brain2(brain1);
    
    // std::cout << "\n=== Test 3: Opérateur d'affectation ===" << std::endl;
    // Brain brain3;
    // brain3 = brain1;
    
    // std::cout << "\n=== Test 4: Modification des idées ===" << std::endl;
    // // Si tu ajoutes des getters/setters, tu peux tester ici
    // // brain1.setIdea(0, "Première idée");
    // // brain2.setIdea(0, "Idée différente");
    
    // std::cout << "\n=== Test 5: Copie avec des données ===" << std::endl;
    // {
    //     Brain brain4;
    //     // Remplir brain4 avec des idées si tu as des setters
    //     Brain brain5(brain4);  // Test copie avec données
    //     Brain brain6;
    //     brain6 = brain4;       // Test affectation avec données
    // } // brain4, brain5, brain6 sont détruits ici
    
    // std::cout << "\n=== Test 6: Auto-affectation ===" << std::endl;
    // brain1 = brain1;  // Test de l'auto-affectation
    
    // std::cout << "\n=== Fin du main - Destruction des objets ===" << std::endl;
    // return 0;
}
