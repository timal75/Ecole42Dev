#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : _name(""), _hitpoints(100), _maxhitpoints(100), _energypoints(50), _maxenergypoints(50), _level(1), _meleedamage(20), _rangeddamage(15), _armorreduction(3)
{
	std::cout <<"Constructor ScavTrap called for "<< ScavTrap::_name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : _name(name), _hitpoints(100), _maxhitpoints(100), _energypoints(50), _maxenergypoints(50), _level(1), _meleedamage(20), _rangeddamage(15), _armorreduction(3)
{
	std::cout <<"Constructor ScavTrap called for "<< ScavTrap::_name << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout <<"Destructor ScavTrap called for "<< ScavTrap::_name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &frt)
{
	*this = frt;
	std::cout <<"Copy Constructor ScavTrap called for "<< ScavTrap::_name << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &frt)
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
	std::cout <<"Assignement Constructor ScavTrap called for "<< ScavTrap::_name << std::endl;
	return (*this);
}

void ScavTrap::rangeAttack(std::string const &frt)
{
	std::cout << this->_name <<" attacks "<< frt <<" at range  causing "<<_rangeddamage << " damages " <<std::endl;
}

void ScavTrap::meleeAttack(std::string const &frt)
{
	std::cout << this->_name << " attacks "<< frt <<" at melee  causing "<<_meleedamage << " damages " <<std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
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


void ScavTrap::berepaired(unsigned int amount)
{

	this->_hitpoints += amount;
	if (this->_hitpoints > 100)
		this->_hitpoints = 100;
	std::cout << this->_name << " is being repaired with "<< amount <<std::endl;
	std::cout << this->_name << " now  has "<< this->_hitpoints << " hit points" <<std::endl;
}

void ScavTrap::challengeNewcomer(void)
{
	std::string poolchal[5]={"challenge 1", "challenge 2","challenge 3","challenge 4", "challenge 5"};
		std::cout <<this->_name << " makes a random " <<poolchal[rand () % 5] << " challenge "<< std::endl;
}
