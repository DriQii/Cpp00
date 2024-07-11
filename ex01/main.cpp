#include "PhoneBook.hpp"

int main()
{
	PhoneBook	phone_book;
	std::string	user_input ;

	std::cout << "Cmd : ";
	std::getline(std::cin, user_input);
	while (user_input.compare("EXIT") != 0)
	{
		if (user_input.compare("ADD") == 0)
			phone_book.add_contact();
		else if (user_input.compare("SEARCH") == 0)
			phone_book.search();
		std::cout << "Cmd : ";
		std::getline(std::cin, user_input);
	}
}
