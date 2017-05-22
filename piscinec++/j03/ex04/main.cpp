#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main (void)
{
	FragTrap   frt;
	FragTrap   frt1 ("toto");
	ScavTrap   frt2;
	ScavTrap   frt3 ("tata");
	ClapTrap   frt4 ("tata");
	ClapTrap   frt5 ;
	NinjaTrap  frt6 ("robert");
	SuperTrap  frt7 ("robert");
	SuperTrap  frt8 ;
	
	frt8 = frt7;
	frt7.rangeAttack("ROUGE");
	frt7.vaulthunter_dot_exe("ROUGE");

	std::cout << "++++++" <<frt8.getlevel();
	return (0);
	frt = frt1;
	frt.rangeAttack("toto");
	frt.meleeAttack("toto");
	frt.takeDamage(1);
	frt.berepaired(15);
	frt.takeDamage(15);
	frt.berepaired(1);
	frt.takeDamage(120);
	frt.berepaired(114);
	frt.vaulthunter_dot_exe("titi");
	frt.vaulthunter_dot_exe("titi");
	frt.vaulthunter_dot_exe("titi");
	frt.vaulthunter_dot_exe("titi");
	frt.vaulthunter_dot_exe("titi");

	frt2 = frt3;
	frt2.rangeAttack("toto");
	frt2.meleeAttack("toto");
	frt2.takeDamage(1);
	frt2.berepaired(15);
	frt2.takeDamage(15);
	frt2.berepaired(1);
	frt2.takeDamage(120);
	frt2.berepaired(114);
	frt2.challengeNewcomer();
	frt2.challengeNewcomer();
	frt2.challengeNewcomer();

	frt6.ninjaShoebox(frt);
	frt6.ninjaShoebox(frt2);
	frt6.ninjaShoebox(frt5);
	return (0);

}
