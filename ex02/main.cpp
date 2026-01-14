#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  std::cout << "--- 1. CONSTRUCTORS ---" << std::endl;
  ClapTrap clap("Clappy");
  ScavTrap scav("Scavvy");
  FragTrap frag("Fraggy");

  std::cout << "\n--- 2. FRAGTRAP ATTACK ---" << std::endl;
  // Shows FragTrap specific stats (30 dmg) and attack message
  frag.attack("Scavvy");
  scav.takeDamage(30);

  std::cout << "\n--- 3. SPECIAL ABILITIES ---" << std::endl;
  // Test ScavTrap specific method
  scav.guardGate();
  // Test FragTrap specific method
  frag.highFivesGuys();

  std::cout << "\n--- 4. INHERITED ACTIONS ---" << std::endl;
  // FragTrap uses ClapTrap's repair logic
  frag.takeDamage(50);
  frag.beRepaired(20);

  std::cout << "\n--- 5. DESTRUCTORS ---" << std::endl;
  // Objects are destroyed in reverse order (Frag -> Scav -> Clap)
  return 0;
}
