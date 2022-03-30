#include <iostream>
#include <cstring>
#include <fstream>

void	replace_write(std::ifstream &read_file, std::ofstream &write_file, char **argv)
{
	std::string	seeking(argv[2]);
	std::string	replacement(argv[3]);
	std::string	line;
	std::size_t	found;
	bool	first = true;

	while (std::getline(read_file, line))
	{
		if (first)
			first = false;
		else
			write_file << '\n';
		found = line.find(seeking);
		while (found != std::string::npos)
		{
			write_file << line.substr(0, found) << replacement;
			line = line.substr(found + seeking.length());
			found = line.find(seeking);
		}
		write_file << line;
	}

}

int	main(int argc, char **argv)
{
	std::string	filename(argv[1]);

	std::ifstream	read_file(filename.c_str());
	std::ofstream	write_file((filename + ".replace").c_str());

	if (argc > 4)
		return (1);

	replace_write(read_file, write_file, argv);
}
