#include "Harl.hpp"

int	main(void)
{
	Harl harl;

	std::cout <<"[DEBUG]" << std::endl;
	harl.complain("DEBUG");
	std::cout <<"[INFO]" << std::endl;
	harl.complain("INFO");
	std::cout <<"[WARNING]" << std::endl;
	harl.complain("WARNING");
	std::cout <<"[ERROR]" << std::endl;
	harl.complain("ERROR");
	std::cout <<"[NOTHING]" << std::endl;
	harl.complain("");
	std::cout <<"[NOT HARL]" << std::endl;
	harl.complain("HELLO");
	return (0);
}
