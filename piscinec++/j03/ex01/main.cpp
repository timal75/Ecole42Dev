#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main (void)
{
	FragTrap   frt;
	FragTrap   frt1 ("toto");
	ScavTrap   frt2;
	ScavTrap   frt3 ("tata");
	
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
	return (0);

}
