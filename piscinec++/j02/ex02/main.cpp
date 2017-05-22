#include <iostream>
#include "Fixed.class.hpp"

int main( void ) {
	Fixed a;
	Fixed b( 254 );
	Fixed t( 8 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	--t;
	std::cout << "t is " << t << std::endl;

	if (b < a)
	std::cout << "a is greater" << a << std::endl;

	std::cout << "max a is greater" << Fixed::max(a,b) << std::endl;
	std::cout << "min a is greater" << Fixed::min(a,b) << std::endl;

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
