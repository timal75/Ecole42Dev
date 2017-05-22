#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void) : FragTrap(""),NinjaTrap("")
{

	std::cout <<"Constructor SuperTrap called for "<< FragTrap::_name << std::endl;
}

SuperTrap::SuperTrap(std::string name) : FragTrap(name), NinjaTrap(name)
{
	std::cout << this->getname();
	std::cout <<"Constructor SuperTrap called for "<< FragTrap::_name << std::endl;
}

SuperTrap::~SuperTrap(void)
{
	std::cout <<"Destructor SuperTrap called for "<< FragTrap::_name << std::endl;
}

std::string SuperTrap::getname(void)
{
	return(FragTrap::_name);
}

int SuperTrap::getmaxhitpoints(void)
{
	return(FragTrap::_maxhitpoints);
}

int SuperTrap::gethitpoints(void)
{
	return(FragTrap::_hitpoints);
}

int SuperTrap::getlevel(void)
{
	return(1);
}

int SuperTrap::getenergypoints(void)
{
	return(NinjaTrap::_energypoints);
}

int SuperTrap::getrangeddamage(void)
{
	return(FragTrap::_rangeddamage);
}

int SuperTrap::getmeleedamage(void)
{
	return(NinjaTrap::_meleedamage);
}

int SuperTrap::getarmorreduction(void)
{
	return(FragTrap::_armorreduction);
}

int SuperTrap::getmaxenergypoints(void)
{
	return(NinjaTrap::_maxhitpoints);
}

void SuperTrap::rangeAttack(std::string const &frt)
{
	return(FragTrap::rangeAttack(frt));
}

void SuperTrap::meleeAttack(std::string const &frt)
{
	return(NinjaTrap::rangeAttack(frt));
}

