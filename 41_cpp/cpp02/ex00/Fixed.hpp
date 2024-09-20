#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					fixed_point;
		static const int	bits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &fixed); //복사 생성자
		Fixed & operator = (const Fixed &fixed); //복사 할당 연산자 오버로드
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw ); 
};

#endif
