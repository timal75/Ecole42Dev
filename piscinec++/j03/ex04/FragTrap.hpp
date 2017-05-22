#ifndef FRAGTRAP_H
# define FRAGTRAP_H
#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
				FragTrap(void);
				FragTrap(std::string name);
				~FragTrap (void);
				void vaulthunter_dot_exe(std::string const &target);

	private :
};
#endif
