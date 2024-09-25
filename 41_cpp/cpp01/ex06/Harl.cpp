#include "Harl.hpp"

Harl::Harl()
{
	this->classname = "[Harl]";
	std::cout << this->classname << OCCF0 << std::endl;
}

Harl::~Harl()
{
	std::cout << this->classname << OCCF3 << std::endl;
}

void Harl::debug( void )
{
	
	std::cout <<"[DEBUG]" << std::endl;
	std::cout << "Debug messages contain contextual information. They are mostly used for problem diagnosis." << std::endl;
}

void Harl::info( void )
{
	std::cout <<"[INFO]" << std::endl;
	std::cout << "Info messages contain extensive information. They are helpful for tracing program execution in a production environment." << std::endl;
}

void Harl::warning( void )
{
	std::cout <<"[WARNING]" << std::endl;
	std::cout << "Warning messages indicate a potential issue in the system. However, it can be handled or ignored" << std::endl;
}

void Harl::error( void )
{
	std::cout <<"[ERROR]" << std::endl;
	std::cout << "Error messages indicate an unrecoverable error has occurred. This is usually a critical issue that requires manual intervention." << std::endl;
}

void Harl::complain(std::string level)
{
	int	index;
	std::string levels[levelsnum] = {"DEBUG", "INFO", "WARNING" ,"ERROR"};

	for (index = 0; index < levelsnum; index++)
	{
		if (levels[index] == level)
			break ;
	}
	switch (index)
	{
		case 0:
			this->debug();
			__attribute__((fallthrough));
		case 1:
			this->info();
			// FALLTHROUGH
		case 2:
			this->warning();
			// FALLTHROUGH
		case 3:
			this->error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;	
	}	
}