#ifndef SCAVTRAP_H
# define SCAVTRAP_H
#include <iostream>
#include <string>

class ScavTrap
{
	public:
				ScavTrap(void);
				ScavTrap(std::string name);
				~ScavTrap (void);
				ScavTrap (ScavTrap const &frt);
				ScavTrap &operator=(ScavTrap const &frt);
				void rangeAttack(std::string const &target);
				void meleeAttack(std::string const &target);
				void takeDamage(unsigned int amount);
				void berepaired(unsigned int amount);	
				void challengeNewcomer(void);

	private :
				std::string _name;
				int	_hitpoints;
				int _maxhitpoints;
				int _energypoints;
				int _maxenergypoints;
				int _level;
				int _meleedamage;
				int _rangeddamage;
				int _armorreduction;
};
#endif
