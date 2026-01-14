#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
  std::cout << "FragTrap Default constructor called" << std::endl;
  this->Hitpoint = 100;
  this->Attackdamage = 30;
  this->Energypoint = 100;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  std::cout << "FragTrap Parameterized constructor called\n";
  this->Hitpoint = 100;
  this->Attackdamage = 30;
  this->Energypoint = 100;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
  std::cout << "FragTrap Copy constructor called" << std::endl;
  *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
  std::cout << "FragTrap Copy assignment operator called" << std::endl;
  if (this != &other) {
    this->name = other.name;
    this->Hitpoint = other.Hitpoint;
    this->Energypoint = other.Energypoint;
    this->Attackdamage = other.Attackdamage;
  }
  return (*this);
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target) {
  if (Energypoint > 0 && Hitpoint > 0) {
    std::cout << "FragTrap " << name << " attacks " << target << ", causing "
              << Attackdamage << " points of damage!\n";
    Energypoint--;
  } else {
    std::cout << "FragTrap " << name
              << " is too weak to attack (HP: " << Hitpoint
              << ", EP: " << Energypoint << ")." << std::endl;
  }
}

void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap " << name << " positive high-fives request\n";
}
