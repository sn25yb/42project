#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_num = 0;
}

// Fixed:: Fixed(const int integer) : fixed_num(integer << this->frac_bit)
Fixed:: Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_num = num << this->frac_bit;
}

Fixed:: Fixed(const float float_num)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_num =  roundf(float_num * (1 << this->frac_bit));
}

Fixed:: Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	// this->fixed_num = fixed.getRawBits();
	*this = fixed;
}

Fixed& Fixed::operator = (const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_num = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_num);
}

void	Fixed::setRawBits( int const raw )
{
	this->fixed_num = raw;
}

//고정 소수점 값을 부동 소수점 값으로 변환
float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->fixed_num) / (1 << this->frac_bit));
}

//고정 소수점 값을 정수 값으로 변환
int	Fixed::toInt( void ) const
{
	return (this->fixed_num >> this->frac_bit);
}
