#include "ScavTrap.hpp"

int main(void) {
  ClapTrap basic("Basic");
  ScavTrap enhanced("Enhanced");

  std::cout << "\n######### Basic vs Enhanced Combat ########\n";
  basic.attack("Enhanced");
  enhanced.attack("Basic");

  std::cout << "\n######### Enhanced takes damage and repairs ########\n";
  enhanced.takeDamage(30);
  enhanced.beRepaired(15);

  std::cout << "\n######### Enhanced enters guard mode ########\n";
  enhanced.guardGate();

  std::cout << "\n######### Enhanced exhausts energy attacking air ########\n";
  for (int i = 0; i < 21; i++)
    enhanced.attack("Air");

  std::cout << "GoodBye\n";
  return 0;
}
