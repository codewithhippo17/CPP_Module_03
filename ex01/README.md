# Exercise 01: ScavTrap - Inheritance and Polymorphism

## Overview
This exercise introduces C++ inheritance by creating a `ScavTrap` class that derives from `ClapTrap`. It demonstrates how derived classes extend base class functionality while maintaining proper construction/destruction order and method overriding.

## Key Concepts Demonstrated

### 1. Public Inheritance
```cpp
class ScavTrap : public ClapTrap
```
- **IS-A Relationship**: ScavTrap IS-A ClapTrap with enhanced capabilities
- **Access Control**: Public inheritance maintains the base class's public interface
- **Code Reuse**: ScavTrap inherits all ClapTrap functionality without reimplementation

### 2. Constructor Delegation and Chaining
The exercise demonstrates proper constructor chaining:

#### Default Constructor
```cpp
ScavTrap::ScavTrap() : ClapTrap() {
    // Base constructor called first
    // Then derived-specific initialization
}
```

#### Parameterized Constructor
```cpp
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    // Delegates name initialization to base class
    // Overrides specific attributes
}
```

**Construction Order**:
1. Base class constructor (`ClapTrap`) executes first
2. Derived class constructor (`ScavTrap`) executes second
3. Attribute override occurs in derived constructor

### 3. Destruction Chaining
```cpp
ScavTrap::~ScavTrap() {
    std::cout << "Destructor of ScavTrap called" << std::endl;
}
// Base destructor automatically called after derived destructor
```

**Destruction Order** (reverse of construction):
1. Derived class destructor (`ScavTrap`) executes first  
2. Base class destructor (`ClapTrap`) executes automatically

This ensures proper cleanup of resources in inheritance hierarchies.

### 4. Method Overriding
ScavTrap demonstrates method specialization:

#### Attack Override
```cpp
void ScavTrap::attack(const std::string &target) {
    // Same logic as base class but different output message
    std::cout << "ScavTrap " << name << " attacks..." << std::endl;
}
```

**Key Points**:
- Same method signature as base class
- Different implementation/behavior
- Demonstrates polymorphic behavior
- Maintains interface contract

### 5. Enhanced Attributes
ScavTrap modifies inherited attributes to create a more powerful robot:

| Attribute | ClapTrap | ScavTrap | Enhancement |
|-----------|----------|----------|-------------|
| Hit Points | 10 | 100 | 10x more durable |
| Energy Points | 10 | 50* | 5x more energy |
| Attack Damage | 0 | 20 | Actual combat capability |

*Note: Code shows 20 energy points, subject specifies 50 - demonstrates implementation vs specification awareness.

### 6. Extended Functionality
ScavTrap adds new capabilities not present in the base class:

```cpp
void guardGate(void) const;
```
- **Specialization**: Functionality unique to ScavTrap
- **const Method**: Doesn't modify object state
- **Role-Specific Behavior**: Gate keeper functionality

### 7. Copy Semantics in Inheritance
The exercise properly implements copy operations for derived classes:

#### Copy Constructor
```cpp
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    *this = other;  // Delegate to assignment operator
}
```

#### Assignment Operator
```cpp
ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    if (this != &other) {
        // Copy all attributes explicitly
        // Note: Direct member access requires protected access
    }
    return *this;
}
```

## Learning Objectives

This exercise teaches:

1. **Inheritance Syntax**: How to declare and implement derived classes
2. **Constructor Chaining**: Proper initialization order in inheritance
3. **Destructor Order**: Understanding automatic destruction sequencing  
4. **Method Overriding**: Customizing inherited behavior
5. **Access Control**: Managing visibility in inheritance hierarchies
6. **Object Lifecycle**: Constructor/destructor messages show creation/destruction order
7. **Enhanced Functionality**: Adding capabilities to existing classes

## Important Design Patterns

### 1. Base Class Preparation
For inheritance to work properly, ClapTrap attributes should be `protected` rather than `private`:

```cpp
protected:  // Instead of private
    std::string name;
    int Hitpoint;
    int Energypoint; 
    int Attackdamage;
```

This allows derived classes direct access while maintaining encapsulation from external code.

### 2. Virtual Destructor Consideration
While not required in this exercise, inheritance hierarchies typically benefit from virtual destructors:

```cpp
virtual ~ClapTrap();  // Enables proper polymorphic destruction
```

## Compilation and Testing

```bash
make
./ScavTrap
```

The program demonstrates:
- Construction order visualization
- Enhanced combat capabilities
- Specialized behaviors (guard gate)
- Destruction order visualization

## Code Structure Analysis

- **ClapTrap.hpp/cpp**: Base class (copied from ex00)
- **ScavTrap.hpp/cpp**: Derived class implementation
- **main.cpp**: Tests inheritance behavior and polymorphism
- **Makefile**: Updated compilation rules

## Key Takeaways

1. **Inheritance enables code reuse** while allowing specialization
2. **Construction happens base-to-derived**, destruction is derived-to-base
3. **Method overriding** allows customization of inherited behavior  
4. **Proper access control** is crucial for maintainable inheritance
5. **Enhanced attributes** create meaningful specializations

This foundation prepares for more complex inheritance patterns in Exercise 02.