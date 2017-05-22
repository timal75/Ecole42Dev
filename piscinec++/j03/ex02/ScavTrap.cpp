#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("", 100, 100, 50, 50, 1, 20, 15, 3 )
{
	std::cout <<"Constructor ScavTrap called for "<< ScavTrap::_name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 100, 50, 50, 1, 20, 15, 3 )
{
	std::cout <<"Constructor ScavTrap called for "<< ScavTrap::_name << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout <<"Destructor ScavTrap called for "<< ScavTrap::_name << std::endl;
}

void ScavTrap::challengeNewcomer(void)
{
	std::string poolchal[5]={"challenge 1", "challenge 2","challenge 3","challenge 4", "challenge 5"};
		std::cout <<this->_name << " makes a random " <<poolchal[rand () % 5] << " challenge "<< std::endl;
}
