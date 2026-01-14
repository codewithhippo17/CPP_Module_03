#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
  std::cout << "ScavTrap Default constructor called" << std::endl;
  this->Hitpoint = 100;
  this->Attackdamage = 50;
  this->Energypoint = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  std::cout << "Parameterized constructor of ScavTrap called\n";
  this->Hitpoint = 100;
  this->Attackdamage = 50;
  this->Energypoint = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  std::cout << "Copy assignment operator of ScavTrap called" << std::endl;
  if (this != &other) {
    this->name = other.name;
    this->Hitpoint = other.Hitpoint;
    this->Energypoint = other.Energypoint;
    this->Attackdamage = other.Attackdamage;
  }
  return (*this);
}

ScavTrap::~ScavTrap() {
  std::cout << "Destructor of ScavTrap called" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
  if (Energypoint > 0 && Hitpoint > 0) {
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing "
              << Attackdamage << " points of damage!\n";
    Energypoint--;
  } else {
    std::cout << "ScavTrap " << name
              << " is too weak to attack (HP: " << Hitpoint
              << ", EP: " << Energypoint << ")." << std::endl;
  }
}

void ScavTrap::guardGate(void) const {
  std::cout << "ScavTrap" << name << "is now in Gate keeper mode.\n";
}
