#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class Claptrap {

private:
  std::string name;
  int Hitpoint;
  int Energypoint;
  int Attackdamage;

public:
  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif
