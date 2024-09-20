#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					fixed_num;
		static const int	frac_bit = 8;
	public:
		Fixed(void);
		Fixed(const int num);
		Fixed(const float float_num);
		Fixed(const Fixed &fixed); //복사 생성자
		Fixed &operator = (const Fixed &fixed); //복사 할당 연산자 오버로드
		~Fixed();
		
		int		getRawBits( void ) const;
		void	setRawBits( int const raw ); 

		float toFloat( void ) const; //고정 소수점 값을 부동 소수점 값으로 변환
		int toInt( void ) const; //고정 소수점 값을 정수 값으로 변환
};

#endif
