#include "Fixed.hpp"


std::ostream &operator << (std::ostream &ostream, const Fixed &fixed)
{
	// ostream << fixed.getRawBits();
	ostream << fixed.toFloat();
	return (ostream);
}

// int main( void )
// {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }

int	main(void)
{
	Fixed a(5);
	Fixed b(2.5f);
	Fixed c(2.5f);

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;

	/* **********/
	/* FUNCTION */
	/* **********/
	std::cout << "== FUNCTION ==" << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	std::cout << Fixed::max( b, c ) << std::endl;

	/* **************************/
	/* [1] comparison operators */
	/* **************************/
	std::cout << "==[1]comparison operators==" << std::endl;	
	if (a > b)
		std::cout << "a > b is TRUE" << std::endl;
	if (b < a)
		std::cout << "b < a is TRUE" << std::endl;
	if (a >= b)
		std::cout << "a >= b is TRUE" << std::endl;
	if (b <= c)
		std::cout << "b <= c is TRUE" << std::endl;
	if (b == c)
		std::cout << "b == c is TRUE" << std::endl;
	if (a != b)
		std::cout << "a != b is TRUE" << std::endl;

	/* **************************/
	/* [2] arithmetic operators */
	/* **************************/
	std::cout << "==[2]arithmetic operators==" << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / b << std::endl;


	/* ***********************************/
	/* [3] increment/decrement operators */
	/* ***********************************/
	std::cout << "==[3]increment/decrement ==" << std::endl;
	std::cout << "  a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "  a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "  a: " << a << std::endl;
	std::cout << "      a: " << a.getRawBits() << std::endl;
	std::cout << "    ++a: " << (++a).getRawBits() << std::endl;
	std::cout << "      a: " << a.getRawBits() << std::endl;
	std::cout << "    a++: " << (a++).getRawBits() << std::endl;
	std::cout << "      a: " << a.getRawBits() << std::endl;
	// std::cout << "(a++)++: " << (a++)++.getRawBits() << std::endl;
	std::cout << "      a: " << a.getRawBits() << std::endl;

	return (0);
}
