#include "ClapTrap.hpp"

int main(void) {
  ClapTrap hero("Hero");
  ClapTrap villain("Villain");

  std::cout << "\n######### hero and Villain Combat start ########\n";
  hero.attack("Villain");
  std::cout
      << "\n######### we take 5 HP from Villain and he repaired himself with "
      << "3########\n";
  villain.takeDamage(5);
  villain.beRepaired(3);

  std::cout << "\n######### villain should die lets take 10 again ########\n";
  villain.takeDamage(10);
  villain.attack("Hero");
  villain.beRepaired(5);

  std::cout << "\n######### we have just AIR left in the game ########\n";
  for (int i = 0; i < 10; i++)
    hero.attack("Air");
  std::cout << "GoodBye\n";
  return 0;
}
