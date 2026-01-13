#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
    : name("default"), Hitpoint(10), Energypoint(10), Attackdamage(0) {
  std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : Hitpoint(10), Energypoint(10), Attackdamage(0) {
  std::cout << "Parameterized constructor called\n";
  this->name = name;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    this->name = other.name;
    this->Hitpoint = other.Hitpoint;
    this->Energypoint = other.Energypoint;
    this->Attackdamage = other.Attackdamage;
  }
  return (*this);
}

ClapTrap::~ClapTrap() { std::cout << "Destructor called" << std::endl; }

void ClapTrap::attack(const std::string &target) {
  if (Energypoint > 0 && Hitpoint > 0) {
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
              << Attackdamage << " points of damage!\n";
    Energypoint--;
  } else {
    std::cout << "ClapTrap " << name
              << " is too weak to attack (HP: " << Hitpoint
              << ", EP: " << Energypoint << ")." << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (this->Hitpoint == 0) {
    std::cout << "ClapTrap " << name << " is already dead! Stop beating it!"
              << std::endl;
    return;
  }
  Hitpoint -= amount;
  if (Hitpoint <= 0) {
    Hitpoint = 0;
  }
  std::cout << "ClapTrap " << name << " takes " << amount
            << " points of damage! (Current HP: " << Hitpoint << ")"
            << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (Energypoint > 0 && Hitpoint > 0) {
    Energypoint--;
    Hitpoint += amount;
    std::cout << "ClapTrap " << name << " repairs itself for " << amount
              << " hit points! (Current HP: " << this->Hitpoint << ")"
              << std::endl;
  } else {
    std::cout << "ClapTrap " << name
              << " tries to repair but has no energy or is dead." << std::endl;
  }
}
