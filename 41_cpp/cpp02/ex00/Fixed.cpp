#include "Fixed.hpp"

/* ************************************************************************** */
/*                           ORTHODOX CANONICAL FORM                          */
/* ************************************************************************** */

Fixed::Fixed(void)
{
	std::cout << "Default constructor called." << std::endl;
	this->fixed_point = 0;
}

Fixed:: Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called." << std::endl;
	this->fixed_point = fixed.getRawBits();
}

Fixed& Fixed::operator = (const Fixed& fixed)
{
	std::cout << "Copy assignment operator called." << std::endl;
	this->fixed_point = fixed.getRawBits();
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

/* ********************/
/* [2] toFlaot, toInt */
/* ********************/

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->fix_num) / (1 << this->frac_bit));
}

int	Fixed::toInt( void ) const
{
	return (this->fix_num >> this->frac_bit);
}