#include "Fixed.hpp"

/* ************************************************************************** */
/*                           ORTHODOX CANONICAL FORM                          */
/* ************************************************************************** */

Fixed::Fixed(void)
{
	std::cout << "Default constructor called." << std::endl;
	this->fix_num = 0;
}

Fixed:: Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = fixed;
}

Fixed& Fixed::operator = (const Fixed& fixed)
{
	std::cout << "Copy assignment operator called." << std::endl;
	this->fix_num = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called." << std::endl;
}

/* ************************************************************************** */
/*                                  FUNCTION                                  */
/* ************************************************************************** */

/* **************/
/* [1] get, set */
/* **************/

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called." << std::endl;
	return (this->fix_num);
}

void	Fixed::setRawBits( int const raw )
{
	this->fix_num = raw;
}
