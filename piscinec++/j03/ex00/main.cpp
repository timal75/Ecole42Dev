#include "FragTrap.hpp"

int main (void)
{
	FragTrap   frt;
	FragTrap   frt1 ("toto");
	
	frt = frt1;;
	frt.rangeAttack("toto");
	frt.meleeAttack("toto");
	frt.takeDamage(1);
	frt.berepaired(15);
	frt.takeDamage(15);
	frt.berepaired(1);
	frt.takeDamage(120);
	frt.berepaired(114);
	frt.vaulthunter_dot_exe("titi");;
	frt.vaulthunter_dot_exe("titi");;
	frt.vaulthunter_dot_exe("titi");;
	frt.vaulthunter_dot_exe("titi");;
	frt.vaulthunter_dot_exe("titi");;
	return (0);

}
