#include "Fixed.hpp"

/* ************************************************************************** */
/*                           ORTHODOX CANONICAL FORM                          */
/* ************************************************************************** */

Fixed::Fixed(void)
{
	// std::cout << "Default constructor called" << std::endl;
	this->fix_num = 0;
}

Fixed:: Fixed(const Fixed& fixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	// this->fix_num = fixed.getRawBits();
	*this = fixed;
}

Fixed& Fixed::operator = (const Fixed& fixed)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->fix_num = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

/* ************************************************************************** */
/*                               CONSTRUCTOR                                  */
/* ************************************************************************** */

Fixed:: Fixed(const int num)
{
	// std::cout << "Int constructor called" << std::endl;
	this->fix_num = num << this->frac_bit;
}

Fixed:: Fixed(const float float_num)
{
	// std::cout << "Float constructor called" << std::endl;
	this->fix_num =  roundf(float_num * (1 << this->frac_bit));
}

/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

/* **************************/
/* [1] comparison operators */
/* **************************/

bool Fixed::operator > (const Fixed& fixed) const
{
	return (this->fix_num > fixed.fix_num);
}

bool Fixed::operator < (const Fixed& fixed) const
{
	return (this->fix_num < fixed.fix_num);
}

bool Fixed::operator >= (const Fixed& fixed) const
{
	return (this->fix_num >= fixed.fix_num);
}

bool Fixed::operator <= (const Fixed& fixed) const
{
	return (this->fix_num <= fixed.fix_num);
}

bool Fixed::operator == (const Fixed& fixed) const
{
	return (this->fix_num == fixed.fix_num);
}

bool Fixed::operator != (const Fixed& fixed) const
{
	return (this->fix_num != fixed.fix_num);
}

/* **************************/
/* [2] arithmetic operators */
/* **************************/

Fixed Fixed::operator + (const Fixed& fixed) const
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator - (const Fixed& fixed) const
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator * (const Fixed& fixed) const
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator / (const Fixed& fixed) const
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

/* ***********************************/
/* [3] increment/decrement operators */
/* ***********************************/

Fixed& Fixed::operator ++ (void)
{
	this->fix_num++;
	return (*this);
}

const Fixed Fixed::operator ++ (int)
{
	Fixed res(*this);
	
	this->fix_num++;
	return (res);
}

Fixed& Fixed::operator -- (void)
{
	this->fix_num--;
	return (*this);
}

const Fixed Fixed::operator -- (int)
{
	Fixed res(*this);
	
	this->fix_num--;
	return (res);
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
/* [2] toInt, toFlaot */
/* ********************/

int	Fixed::toInt( void ) const
{
	return (this->fix_num >> this->frac_bit);
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->fix_num) / (1 << this->frac_bit));
}

/* **************/
/* [3] min, max */
/* **************/

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1 < fixed2)
		return (fixed1);
	return (fixed2);
}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1 > fixed2)
		return (fixed1);
	return (fixed2);
}

const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1 < fixed2)
		return (fixed1);
	return (fixed2);
}

const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1 > fixed2)
		return (fixed1);
	return (fixed2);
}
