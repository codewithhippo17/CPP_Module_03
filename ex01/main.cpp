#include "ClapTrap.hpp"

int main(void) {
  ClapTrap hero("Hero");
  ClapTrap villain("Villain");

  hero.attack("Villain");
  villain.takeDamage(5);
  villain.beRepaired(3);

  villain.takeDamage(10);
  villain.attack("Hero");
  villain.beRepaired(5);

  for (int i = 0; i < 10; i++)
    hero.attack("Air");
  std::cout << "GoodBye/n";
  return 0;
}
