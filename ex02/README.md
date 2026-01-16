# Exercise 02: FragTrap - Multiple Inheritance Patterns & Class Hierarchies

## Overview
This exercise extends the inheritance hierarchy by adding `FragTrap` as another derived class from `ClapTrap`. It demonstrates how multiple classes can inherit from the same base class, creating sibling relationships in the inheritance tree, and showcases different specialization strategies.

## Key Concepts Demonstrated

### 1. Parallel Inheritance Structure
```
     ClapTrap (Base Class)
        /        \
   ScavTrap    FragTrap
  (Sibling)   (Sibling)
```

Both `ScavTrap` and `FragTrap` inherit from `ClapTrap`, creating a parallel inheritance structure where:
- Both classes share the same base functionality
- Each provides different specializations
- Neither inherits from the other
- Both can coexist in the same program

### 2. Different Specialization Strategies

#### FragTrap Specialization Profile
| Attribute | ClapTrap | ScavTrap | FragTrap | Purpose |
|-----------|----------|----------|----------|---------|
| Hit Points | 10 | 100 | 100 | High durability |
| Energy Points | 10 | 50* | 100 | Maximum sustainability |
| Attack Damage | 0 | 20 | 30 | Highest damage output |

*Note: ScavTrap implementation shows 20 instead of specified 50

**Design Philosophy**:
- **ScavTrap**: Balanced guardian (moderate energy, defensive abilities)
- **FragTrap**: High-energy attacker (maximum energy and damage)

### 3. Constructor/Destructor Chaining Patterns

#### Construction Order in Multi-Class Scenarios
When creating multiple objects of different derived classes:

```cpp
ClapTrap clap("Clappy");    // 1. ClapTrap constructor only
ScavTrap scav("Scavvy");    // 2. ClapTrap → ScavTrap constructors  
FragTrap frag("Fraggy");    // 3. ClapTrap → FragTrap constructors
```

**Key Observation**: Each derived object creates its own base class instance.

#### Destruction Order
```cpp
// Destruction happens in reverse order:
// 3. FragTrap destructor → ClapTrap destructor
// 2. ScavTrap destructor → ClapTrap destructor  
// 1. ClapTrap destructor only
```

### 4. Method Overriding Consistency

Both derived classes override the same base method with different implementations:

#### ScavTrap Attack
```cpp
std::cout << "ScavTrap " << name << " attacks " << target << "...";
```

#### FragTrap Attack  
```cpp
std::cout << "FragTrap " << name << " attacks " << target << "...";
```

**Pattern**: Same interface, different messages - demonstrates polymorphic behavior.

### 5. Unique Specialized Methods

Each derived class adds its own unique functionality:

#### ScavTrap Specialization
```cpp
void guardGate(void) const;  // Defensive capability
```
- Gate keeper mode functionality
- Defensive/protective role
- const method (no state modification)

#### FragTrap Specialization  
```cpp
void highFivesGuys(void);    // Social capability
```
- Positive social interaction
- Non-const method
- Demonstrates different behavioral patterns

### 6. Class Responsibility Patterns

The exercise demonstrates the **Single Responsibility Principle** in inheritance:

- **ClapTrap**: Core robot functionality (health, energy, basic combat)
- **ScavTrap**: Guardian role specialization + gate keeping
- **FragTrap**: High-performance combat + social interaction

Each class has a focused responsibility while building on shared foundations.

### 7. Implementation Inheritance vs Interface

This exercise shows **implementation inheritance** where:
- Derived classes inherit actual implementation from base class
- Base class provides concrete functionality
- Derived classes extend and override as needed
- No abstract interfaces or pure virtual methods

## Advanced Concepts Illustrated

### 1. Object Slicing Awareness
```cpp
ClapTrap* ptr = new FragTrap("Test");  // Possible but loses FragTrap-specific methods
```
Understanding when and how derived objects can be treated as base objects.

### 2. Method Resolution
When calling inherited methods:
```cpp
FragTrap frag("Test");
frag.takeDamage(10);     // Calls ClapTrap::takeDamage (inherited)
frag.attack("Enemy");    // Calls FragTrap::attack (overridden)
frag.highFivesGuys();    // Calls FragTrap::highFivesGuys (unique)
```

### 3. Memory Layout Considerations
Each FragTrap object contains:
- All ClapTrap member variables
- FragTrap's own vtable (if virtual methods existed)
- Same memory footprint as base class (no additional data members)

## Learning Objectives

This exercise teaches:

1. **Multi-Class Inheritance**: How multiple classes can derive from one base
2. **Sibling Relationships**: Classes at the same inheritance level
3. **Specialization Patterns**: Different ways to extend base functionality
4. **Constructor Coordination**: Managing initialization in complex hierarchies
5. **Method Resolution**: How the compiler resolves method calls
6. **Behavioral Polymorphism**: Same interface, different implementations
7. **Class Design**: Organizing responsibilities across inheritance hierarchies

## Design Pattern Recognition

### 1. Template Method Pattern (Implicit)
Base class provides the template (attack structure), derived classes customize the details (messages).

### 2. Strategy Pattern Elements  
Different classes provide different "strategies" for combat and special abilities.

### 3. Factory Method Potential
The structure supports factory patterns where different robot types could be created based on requirements.

## Testing Strategy

The main.cpp demonstrates comprehensive testing:

```cpp
// 1. Construction order verification
ClapTrap clap("Clappy");
ScavTrap scav("Scavvy"); 
FragTrap frag("Fraggy");

// 2. Polymorphic behavior testing
frag.attack("Scavvy");          // FragTrap's version
scav.takeDamage(30);            // Inherited method

// 3. Unique functionality testing  
scav.guardGate();               // ScavTrap-specific
frag.highFivesGuys();           // FragTrap-specific

// 4. Inherited functionality testing
frag.takeDamage(50);            // Base class method
frag.beRepaired(20);            // Base class method

// 5. Destruction order verification (automatic)
```

## Key Architectural Insights

### 1. Horizontal Scaling
Adding new robot types (FragTrap) doesn't require modifying existing classes.

### 2. Vertical Consistency
All robots share the same fundamental interface while allowing specialization.

### 3. Maintainability
Changes to base functionality automatically propagate to all derived classes.

### 4. Extensibility  
New robot types can be added easily by inheriting from ClapTrap.

## Common Inheritance Pitfalls Avoided

1. **Diamond Problem**: Not applicable (single inheritance only)
2. **Slicing**: Demonstrated awareness through proper object handling
3. **Constructor Issues**: Proper base class initialization
4. **Destructor Problems**: Correct destruction order maintained

## Compilation and Execution

```bash
make
./FragTrap
```

Expected output shows:
1. Construction messages in proper order
2. Method overriding behavior  
3. Unique method functionality
4. Destruction messages in reverse order

This exercise completes the foundation of C++ inheritance concepts, preparing for more advanced topics like virtual functions, abstract classes, and multiple inheritance.