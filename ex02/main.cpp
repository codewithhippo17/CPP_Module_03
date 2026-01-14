#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  std::cout << "--- 1. CONSTRUCTORS ---" << std::endl;
  ClapTrap clap("Clappy");
  ScavTrap scav("Scavvy");
  FragTrap frag("Fraggy");

  std::cout << "\n--- 2. FRAGTRAP ATTACK ---" << std::endl;
  frag.attack("Scavvy");
  scav.takeDamage(30);

  std::cout << "\n--- 3. SPECIAL ABILITIES ---" << std::endl;
  scav.guardGate();
  frag.highFivesGuys();

  std::cout << "\n--- 4. INHERITED ACTIONS ---" << std::endl;
  frag.takeDamage(50);
  frag.beRepaired(20);

  std::cout << "\n--- 5. DESTRUCTORS ---" << std::endl;
  return 0;
}
