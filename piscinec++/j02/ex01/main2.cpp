
#include <iostream>

int main (void)
{
	double b ;

	b = 12345678901234567.43 ;
	std::cout << "b est : "<< b << std::endl;
	std::cout << "b >> est : "<< b << std::endl;
	b = b  / (1 << 8);
	std::cout << "trandsform b est : "<< b << std::endl;

	c = 2221;
	std::cout << "c est : "<< c << std::endl;
	c = c << 8;
	std::cout << "c << est : "<< c << std::endl;
	c = c >> 8;
	std::cout << "trandsform c est : "<< c << std::endl;

}
