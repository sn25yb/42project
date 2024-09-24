#include "Fixed.hpp"

/* ************************************************************************** */
/*                           ORTHODOX CANONICAL FORM                          */
/* ************************************************************************** */

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->fix_num = 0;
}

Fixed:: Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	// this->fix_num = fixed.getRawBits();
	*this = fixed;
}

Fixed& Fixed::operator = (const Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fix_num = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/* ************************************************************************** */
/*                               CONSTRUCTOR                                  */
/* ************************************************************************** */
// Fixed:: Fixed(const int integer) : fix_num(integer << this->frac_bit)
Fixed:: Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->fix_num = num << this->frac_bit;
}

Fixed:: Fixed(const float float_num)
{
	std::cout << "Float constructor called" << std::endl;
	this->fix_num =  roundf(float_num * (1 << this->frac_bit));
}

/* ************************************************************************** */
/*                                  FUNCTION                                  */
/* ************************************************************************** */

/* **************/
/* [1] get, set */
/* **************/

int	Fixed::getRawBits( void ) const
{
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