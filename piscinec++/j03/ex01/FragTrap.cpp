#include "FragTrap.hpp"

FragTrap::FragTrap(void) : _name(""), _hitpoints(100), _maxhitpoints(100), _energypoints(100), _maxenergypoints(100), _level(1), _meleedamage(30), _rangeddamage(20), _armorreduction(5)
{
	std::cout <<"Constructor FragTrap called for "<< FragTrap::_name << std::endl;
}

FragTrap::FragTrap(std::string name) : _name(name), _hitpoints(100), _maxhitpoints(100), _energypoints(100), _maxenergypoints(100), _level(1), _meleedamage(30), _rangeddamage(20), _armorreduction(5)
{
	std::cout <<"Constructor FragTrap called for "<< FragTrap::_name << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout <<"Destructor FragTrap called for "<< FragTrap::_name << std::endl;
}

FragTrap::FragTrap(FragTrap const &frt)
{
	*this = frt;
	std::cout <<"Copy Constructor FragTrap called for "<< FragTrap::_name << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &frt)
{
	this->_name = frt._name;
	this->_hitpoints = frt._hitpoints;
	this->_maxhitpoints = frt._maxhitpoints;
	this->_energypoints = frt._energypoints;
	this->_maxenergypoints = frt._maxenergypoints;
	this->_level = frt._level;
	this->_meleedamage = frt._meleedamage;
	this->_rangeddamage = frt._rangeddamage;
	this->_armorreduction = frt._armorreduction;
	std::cout <<"Assignement Constructor FragTrap called for "<< FragTrap::_name << std::endl;
	return (*this);
}

void FragTrap::rangeAttack(std::string const &frt)
{
	std::cout << this->_name <<" attacks "<< frt <<" at range  causing "<<_rangeddamage << " damages " <<std::endl;
}

void FragTrap::meleeAttack(std::string const &frt)
{
	std::cout << this->_name << " attacks "<< frt <<" at melee  causing "<<_meleedamage << " damages " <<std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	int damage;

	damage = amount - this->_armorreduction;
	if (damage < 0)
		damage = 0;
	this->_hitpoints -= damage;
	if (this->_hitpoints < 0)
		this->_hitpoints = 0;
	std::cout << this->_name << " is attacked with "<< amount << " damages " <<std::endl;
	std::cout << this->_name << " takes "<< damage << " damages " <<std::endl;
	std::cout << this->_name << " still has "<< this->_hitpoints << " hit points" <<std::endl;
}


void FragTrap::berepaired(unsigned int amount)
{

	this->_hitpoints += amount;
	if (this->_hitpoints > 100)
		this->_hitpoints = 100;
	std::cout << this->_name << " is being repaired with "<< amount <<std::endl;
	std::cout << this->_name << " now  has "<< this->_hitpoints << " hit points" <<std::endl;
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
