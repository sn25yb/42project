#include <iostream>

int	valid_argv(int argc)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	megaphone(char **str)
{
	std::string	res;
	int			index;
	int			index2;

	for (index = 0; str[index]; index++)
		for (index2 = 0; str[index][index2]; index2++)
			res += static_cast<char>(std::toupper(str[index][index2]));
	std::cout << res << std::endl;
}

int	main(int argc, char **argv)
{
	if (valid_argv(argc))
		return (EXIT_SUCCESS);
	megaphone(++argv);
	return (0);
}

/* TEST CASE */
// ./megaphone "shhhhh... I think the students are asleep..."
// ./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
// ./megaphone
