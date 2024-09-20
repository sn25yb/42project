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
		/* : Default constructor, Copy constructor, Copy assignment operator, Destructor */
		Fixed(void);
		Fixed(const Fixed& fixed);
		Fixed& operator = (const Fixed& fixed);
		~Fixed();
		/* */
		Fixed(const int num);
		Fixed(const float float_num);

		/* OPERATORS */
		/* [1] comparison operators */
		bool operator > (const Fixed& fixed) const ;
		bool operator < (const Fixed& fixed) const ;
		bool operator >= (const Fixed& fixed) const ;
		bool operator <= (const Fixed& fixed) const ;
		bool operator == (const Fixed& fixed) const ;
		bool operator != (const Fixed& fixed) const ;
		/* [2] arithmetic operators */
		Fixed operator + (const Fixed& fixed);
		Fixed operator - (const Fixed& fixed);
		Fixed operator * (const Fixed& fixed);
		Fixed operator / (const Fixed& fixed);
		/* [3] increment/decrement */
		Fixed& operator ++ (void);
		const Fixed operator ++ (int);
		Fixed& operator -- (void);
		const Fixed operator -- (int);

		/* FUNCTION */
		/* [2] get/set */
		int		getRawBits( void ) const;
		void	setRawBits( int const raw ); 
		/* [2] toFlaot/toInt */
		float toFloat( void ) const; //고정 소수점 값을 부동 소수점 값으로 변환
		int toInt( void ) const; //고정 소수점 값을 정수 값으로 변환
		/* [3] min/max */
		static Fixed& min(Fixed& fixed1, Fixed& fixed2);
		static Fixed& max(Fixed& fixed1, Fixed& fixed2);
		static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
		static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);

};

#endif
