#include <iostream>
#include <cctype>

void print_upper(char *str)
{
	for (int i = 0; str[i]; i++)
		std::cout << (char)toupper(str[i]);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; i++)
		print_upper(argv[i]);
	std::cout << std::endl;
	return (0);
}
