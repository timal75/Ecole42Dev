#ifndef CLAPTRAP_H
# define CLAPTRAP_H
#include <iostream>
#include <string>

class ClapTrap
{
	public:
				ClapTrap(void);
				ClapTrap(std::string name);
				ClapTrap(std::string name , int hipoints, int maxhitpoints, 
						int energypoints, int maxenergypoints, int level , 
						int meleedamage, int rangedamage, int armorreduction);
				~ClapTrap (void);
				ClapTrap (ClapTrap const &frt);
				ClapTrap &operator=(ClapTrap const &frt);
				void rangeAttack(std::string const &target);
				void meleeAttack(std::string const &target);
				void takeDamage(unsigned int amount);
				void berepaired(unsigned int amount);	

	protected :
				std::string _name;
				int	_hitpoints;
				int _maxhitpoints;
				int _energypoints;
				int _maxenergypoints;
				int _level;
				int _meleedamage;
				int _rangeddamage;
				int _armorreduction;

	private :
};
#endif
