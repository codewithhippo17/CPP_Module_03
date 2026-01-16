# Exercise 00: ClapTrap - Basic Class Implementation

## Overview
This exercise introduces fundamental C++ Object-Oriented Programming (OOP) concepts through the implementation of a simple `ClapTrap` class. It serves as the foundation for understanding class design, encapsulation, and the Orthodox Canonical Form.

## Key Concepts Demonstrated

### 1. Class Design and Encapsulation
- **Private Attributes**: The class demonstrates proper encapsulation by keeping all data members private:
  - `name`: Robot's identifier (passed as constructor parameter)
  - `Hitpoint`: Health value (initialized to 10)
  - `Energypoint`: Energy for actions (initialized to 10)
  - `Attackdamage`: Damage dealt in attacks (initialized to 0)

- **Public Interface**: Clean separation between internal state and external interface through public member functions.

### 2. Orthodox Canonical Form (OCF)
The class implements the complete Orthodox Canonical Form:
- **Default Constructor**: `ClapTrap()` - Creates with default values
- **Copy Constructor**: `ClapTrap(const ClapTrap &other)` - Deep copy semantics
- **Copy Assignment Operator**: `operator=` - Self-assignment protection and proper copying
- **Destructor**: `~ClapTrap()` - Clean resource management

### 3. Resource Management
- **Energy System**: Actions consume energy points, preventing unlimited actions
- **State Validation**: Methods check for valid states (alive and has energy) before executing
- **Boundary Conditions**: Proper handling of edge cases (death, zero energy)

### 4. Method Implementation Patterns
The class demonstrates different method behaviors:

#### Attack Method
```cpp
void attack(const std::string& target);
```
- Validates state before execution (HP > 0 && Energy > 0)
- Consumes 1 energy point per attack
- Provides clear feedback messages
- Handles failure cases gracefully

#### Damage Method
```cpp
void takeDamage(unsigned int amount);
```
- Reduces hit points by damage amount
- Prevents damage to already dead units
- Ensures HP doesn't go below 0
- Provides status feedback

#### Repair Method
```cpp
void beRepaired(unsigned int amount);
```
- Consumes energy to restore health
- Validates prerequisites (alive and has energy)
- Increases hit points
- Shows current status after repair

### 5. Constructor Design Patterns
- **Member Initialization Lists**: Efficient initialization using initialization lists
- **Parameter Constructor**: `ClapTrap(std::string name)` for named instances
- **Debug Output**: All constructors/destructor print messages for lifecycle tracking

## Learning Objectives

This exercise teaches:

1. **Basic Class Structure**: How to define and implement a C++ class
2. **Encapsulation**: Separating interface from implementation
3. **Constructor Patterns**: Different ways to initialize objects
4. **State Management**: Maintaining valid object state across operations
5. **Method Design**: Creating robust methods with validation
6. **Debug Techniques**: Using output to track object lifecycle

## Compilation and Testing

```bash
make
./ClapTrap
```

The program demonstrates:
- Object creation and initialization
- Combat mechanics (attack/damage/repair)
- Energy depletion effects
- State transition handling

## Code Organization

- `ClapTrap.hpp`: Class declaration and interface
- `ClapTrap.cpp`: Implementation with proper error handling
- `main.cpp`: Comprehensive testing scenarios
- `Makefile`: Build configuration with proper flags

This foundation prepares for inheritance concepts in subsequent exercises.