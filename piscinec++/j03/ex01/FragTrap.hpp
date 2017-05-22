#ifndef FRAGTRAP_H
# define FRAGTRAP_H
#include <iostream>
#include <string>

class FragTrap
{
	public:
				FragTrap(void);
				FragTrap(std::string name);
				~FragTrap (void);
				FragTrap (FragTrap const &frt);
				FragTrap &operator=(FragTrap const &frt);
				void rangeAttack(std::string const &target);
				void meleeAttack(std::string const &target);
				void takeDamage(unsigned int amount);
				void berepaired(unsigned int amount);	
				void vaulthunter_dot_exe(std::string const &target);

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
