#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("", 100, 100, 100, 100, 1, 30, 20, 5 )
{
	std::cout <<"Constructor FragTrap called for "<< FragTrap::_name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 100, 100, 1, 30, 20, 5 )
{
	std::cout <<"Constructor FragTrap called for "<< FragTrap::_name << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout <<"Destructor FragTrap called for "<< FragTrap::_name << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const &frt)
{
	std::string poolattack[5]={"Attack1", "Attack2","Attack3","Attack4", "Attack5"};
	if (this->_energypoints < 25)
		std::cout << this->_name << " out of energy"<<std::endl;
	else
	{
		this->_energypoints -= 25;
		std::cout <<this->_name << " makes a random " <<poolattack[rand () % 5] << " on "<<frt<< std::endl;
	}
}
