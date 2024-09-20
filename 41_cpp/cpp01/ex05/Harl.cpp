#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug( void )
{
	std::cout << "Debug messages contain contextual information. They are mostly used for problem diagnosis." << std::endl;
}

void Harl::info( void )
{
	std::cout << "Info messages contain extensive information. They are helpful for tracing program execution in a production environment." << std::endl;
}

void Harl::warning( void )
{
	std::cout << "Warning messages indicate a potential issue in the system. However, it can be handled or ignored" << std::endl;
}

void Harl::error( void )
{
	std::cout << "Error messages indicate an unrecoverable error has occurred. This is usually a critical issue that requires manual intervention." << std::endl;
}


void Harl::complain( std::string level )
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING" ,"ERROR"};
	void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int index = 0; index < 4; index++)
		if (levels[index] == level)
			(this->*f[index])();
}
