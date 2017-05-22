#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name(""), _hitpoints(100), _maxhitpoints(100), _energypoints(100), _maxenergypoints(100), _level(1), _meleedamage(30), _rangeddamage(20), _armorreduction(5)
{
	std::cout <<"Constructor ClapTrap called for "<< ClapTrap::_name << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(100), _maxhitpoints(100), _energypoints(100), _maxenergypoints(100), _level(1), _meleedamage(30), _rangeddamage(20), _armorreduction(5)
{
	std::cout <<"Constructor ClapTrap called for "<< ClapTrap::_name << std::endl;
}

ClapTrap::ClapTrap(std::string name , int hitpoints, int maxhitpoints, int energypoints, int maxenergypoints, int level , int meleedamage, int rangedamage, int armorreduction) : _name(name), _hitpoints(hitpoints), _maxhitpoints(maxhitpoints), _energypoints(energypoints), _maxenergypoints(maxenergypoints), _level(level), _meleedamage(meleedamage), _rangeddamage(rangedamage), _armorreduction(armorreduction)
{
	std::cout <<"Constructor ClapTrap called for "<< ClapTrap::_name << std::endl;
}
ClapTrap::~ClapTrap(void)
{
	std::cout <<"Destructor ClapTrap called for "<< ClapTrap::_name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &frt)
{
	*this = frt;
	std::cout <<"Copy Constructor ClapTrap called for "<< ClapTrap::_name << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &frt)
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
	std::cout <<"Assignement Constructor ClapTrap called for "<< ClapTrap::_name << std::endl;
	return (*this);
}

void ClapTrap::rangeAttack(std::string const &frt)
{
	std::cout << this->_name <<" attacks "<< frt <<" at range  causing "<<_rangeddamage << " damages " <<std::endl;
}

void ClapTrap::meleeAttack(std::string const &frt)
{
	std::cout << this->_name << " attacks "<< frt <<" at melee  causing "<<_meleedamage << " damages " <<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
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


void ClapTrap::berepaired(unsigned int amount)
{

	this->_hitpoints += amount;
	if (this->_hitpoints > this->_maxhitpoints)
		this->_hitpoints = this->_maxhitpoints;
	std::cout << this->_name << " is being repaired with "<< amount <<std::endl;
	std::cout << this->_name << " now  has "<< this->_hitpoints << " hit points" <<std::endl;
}

