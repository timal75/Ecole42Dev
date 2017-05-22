#ifndef NINJATRAP_H
# define NINJATRAP_H
#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
	public	:
				NinjaTrap(void);
				NinjaTrap(std::string name);
				~NinjaTrap (void);
				void ninjaShoebox(NinjaTrap frt);
				void ninjaShoebox(ClapTrap frt);
				void ninjaShoebox(FragTrap frt);
				void ninjaShoebox(ScavTrap frt);

	private :
};
#endif
