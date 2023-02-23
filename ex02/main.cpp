
#include "Fixed.hpp"

#include <iostream>

int	main( void ) 
{
	Fixed 		a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}

// int	main( void ) 
// {
// 	Fixed 		a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

// 	std::cout << "3 > 2 = " << (Fixed(3) > Fixed(2)) << std::endl;

// 	std::cout << "3 < 2 = " << (Fixed(3) < Fixed(2)) << std::endl;

// 	std::cout << "3 == 2 = " << (Fixed(3) == Fixed(2)) << std::endl;

// 	std::cout << "3 != 2 = " << (Fixed(3) != Fixed(2)) << std::endl;

// 	std::cout << "2 == 2 = " << (Fixed(2) == Fixed(2)) << std::endl;

// 	std::cout << "2 <= 2 = " << (Fixed(2) <= Fixed(2)) << std::endl;

// 	std::cout << "2 >= 2 = " << (Fixed(2) >= Fixed(2)) << std::endl;

// 	std::cout << "a * b = " << a * b << std::endl;
// 	std::cout << "a = " << a << std::endl;
// 	std::cout << "b = " << b << std::endl;
	
// 	std::cout << "a * 3 = " << a * 3 << std::endl;
// 	std::cout << "a = " << a << std::endl;

// 	std::cout << "a / 2 " << a / 2 << std::endl;
// 	std::cout << "a = " << a << std::endl;

// 	std::cout << "a - 1" << a - 1 << std::endl;
// 	std::cout << "a = " << a << std::endl;

// 	std::cout << "max (a,b) = "<< Fixed::max( a, b ) << std::endl;

// 	return 0;
// }