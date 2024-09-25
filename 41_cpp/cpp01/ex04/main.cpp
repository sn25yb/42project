#include <iostream>
#include <fstream>

int			valid_argv(int argc, char **argv);
int			ioreplace(char **argv);
std::string	replace_string(const std::string str, const std::string old_str, const std::string new_str);

int	main(int argc, char **argv)
{
	if (valid_argv(argc, argv))
		return (1);
	return (ioreplace(argv + 1));
}

int	valid_argv(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "You need to enter 3 arguments." << std::endl;
		return (1);
	}
	if (!**(argv + 1) || !**(argv + 2))
	{
		std::cerr << "You can't enter empty argument." << std::endl;
		return (1);		
	}
	return (0);
}

int	ioreplace(char **argv)
{
	std::string filename;
	std::string s1;
	std::string s2;
	std::string text;

	//save arguments
	filename = *(argv);
	s1 = *(argv + 1);
	s2 = *(argv + 2);
	//open file for read
	std::ifstream infile;
	infile.open(filename);
	if (infile.fail())
	{
		std::cerr << "We failed to open the file." << std::endl;
		return (1);
	}
	//open file for write
	std::ofstream outfile(filename + ".replace");
	if (outfile.fail())
	{
		std::cerr << "We failed to open the file." << std::endl;
		return (1);
	}
	//read
	while (1)
	{
		std::getline(infile, text);
		if (infile.eof() || infile.fail())
			break ;
		//write
		outfile << replace_string(text, s1, s2) << std::endl;
	}
	//write
	if (infile.eof() && !text.empty()) 
		outfile << replace_string(text, s1, s2);
	//close
	infile.close();
	outfile.close();
	return (0);
}

std::string	replace_string(const std::string str, const std::string old_str, const std::string new_str)
{
	std::string result;
	std::string::size_type pos, old_pos;

	pos = 0;
	old_pos = 0;
	while (1)
	{
		pos = str.find(old_str, old_pos);
		if (pos == std::string::npos)
			break ;
		result.append(str, old_pos, pos - old_pos);
		result += new_str;
		old_pos = pos + old_str.length();
	}
	result.append(str, old_pos, std::string::npos);
	return (result);
}