#ifndef SUPERTRAP_H
# define SUPERTRAP_H
#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : virtual public FragTrap, virtual public NinjaTrap
{
	public	:
				SuperTrap(void);
				SuperTrap(std::string name);
				~SuperTrap (void);
				std::string getname();
				int gethitpoints();
				int getmaxhitpoints();
				int getenergypoints();
				int getmaxenergypoints();
				int getlevel();
				void rangeAttack(std::string const &frt);
				void meleeAttack(std::string const &frt);
				int getarmorreduction();
				int getrangeddamage();
				int getmeleedamage();

	private :
};
#endif
