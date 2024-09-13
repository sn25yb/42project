#include <iostream>
#include <fstream>
#include <stdio.h>

int valid_argv(int argc)
{
	if (argc != 4)
	{
		std::cerr << "The number of factors should be 4" << std::endl;
		return (1);
	}
	return (0);
}


int	main(int argc, char **argv)
{
	std::string filename;
	std::string s1;
	std::string s2;
	std::string file;

	if (valid_argv(argc))
		return (1);
	filename = *(argv + 1);
	s1 = *(argv + 2);
	s2 = *(argv + 3);
	
	//open file for read
	std::ifstream fin;
	fin.open(filename);
	if (!fin)
	{
		std::cerr << "file open is falied." << std::endl;
		return (1);
	}
	//read file
	fin >> file;
	printf("%s\n", file.c_str());
	fin >> file;


	fin.close();
	return (0);
}
