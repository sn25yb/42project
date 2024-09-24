#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					fix_num;
		static const int	frac_bit = 8;
	public:
		/* ORTHODOX CANONICAL FORM */
		Fixed(void);
		Fixed(const Fixed &fixed);
		Fixed &operator = (const Fixed &fixed);
		~Fixed();
		/* CONSTRUCTOR */
		Fixed(const int num);
		Fixed(const float float_num);
		/* FUNCTION */
		/* [1] get, set */
		int		getRawBits( void ) const;
		void	setRawBits( int const raw ); 
		/* [2] toFlaot, toInt */
		float	toFloat( void ) const;
		int		toInt( void ) const; 
};

#endif
