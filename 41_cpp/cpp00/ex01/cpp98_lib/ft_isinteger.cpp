#include "cpp98_lib.hpp"

int ft_isinteger(std::string str)
{
	std::istringstream	iss;
	int					integer;

	iss.str(str);
	iss >> integer;
	return (!iss.fail() && iss.eof());
}

