#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void) : ClapTrap("", 60, 60, 120, 120, 1, 60, 5, 0 )
{
	std::cout <<"Constructor NinjaTrap called for "<< NinjaTrap::_name << std::endl;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name, 60, 60, 120, 120, 1, 600, 5, 0 )
{
	std::cout <<"Constructor NinjaTrap called for "<< NinjaTrap::_name << std::endl;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout <<"Destructor NinjaTrap called for "<< NinjaTrap::_name << std::endl;
}

void NinjaTrap::ninjaShoebox(NinjaTrap frt)
{
	std::cout << this->_name <<" attacks NinjaTrap "<< frt.getName()<< std::endl;
}

void NinjaTrap::ninjaShoebox(ClapTrap frt)
{
	std::cout << this->_name <<" attacks ClapTrap "<< frt.getName() << std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap frt)
{
	std::cout << this->_name <<" attacks FragTrap "<< frt.getName() << std::endl;
}

void NinjaTrap::ninjaShoebox(ScavTrap frt)
{
	std::cout << this->_name <<" attacks ScavTrap "<< frt.getName() << std::endl;
}

