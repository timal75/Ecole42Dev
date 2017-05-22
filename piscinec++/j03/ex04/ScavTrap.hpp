#ifndef SCAVTRAP_H
# define SCAVTRAP_H
#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
				ScavTrap(void);
				ScavTrap(std::string name);
				~ScavTrap (void);
				void challengeNewcomer(void);

	private :
};
#endif
