#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_nb_contact = 0;
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::add_contact(void)
{
	static	int i = 0;;

	this->_contact[i].assign_information();
	i++;
	if ( i == 8)
		i = 0;
	if (_nb_contact < 8)
		_nb_contact += 1;
}
std::string print_information(std::string str)
{
	std::string	space(10, ' ');

	if (str.size() >= 10)
	{
		str.erase(10);
		str[9] = '.';
		return (str);
	}
	else
	{
		space.replace(10 - str.size(), str.size(), str);
		return (space);
	}
}
int	PhoneBook::_request_user_index()
{
	std::string user_input;
	int			nb_input;

	nb_input = 0;
	std::cout << "\n";
	while (nb_input > _nb_contact || nb_input < 1)
	{
		std::cout << "Enter an index between 1 and " << _nb_contact << " : ";
		std::getline(std::cin, user_input);
		nb_input = atoi(user_input.c_str());
	}
	return (nb_input);
}


void PhoneBook::search(void)
{
	int	nb_input;

	if (this->_nb_contact == 0)
	{
		std::cout << "\nPhoneBook is empty\n" << std::endl;
		return;
	}
	std::cout << "\n   Index  |First name|Last name |Nickname  |" << std::endl;
	for(int i = 0; i < this->_nb_contact; i++)
	{
		std::cout << "     " << i + 1 << "    |" << print_information(this->_contact[i].get_first_name()) << "|"
		<< print_information(this->_contact[i].get_last_name()) << "|"
		<< print_information(this->_contact[i].get_nickname()) << "|" << std::endl;
	}
	nb_input = this->_request_user_index();
	std::cout << "\nFirst name : " << this->_contact[nb_input - 1].get_first_name() << std::endl;
	std::cout << "Last name : " << this->_contact[nb_input - 1].get_last_name() << std::endl;
	std::cout << "Nickname : " << this->_contact[nb_input - 1].get_nickname() << std::endl;
	std::cout << "Phone number : " << this->_contact[nb_input - 1].get_phone_number() << std::endl;
	std::cout << "Darkest secret : " << this->_contact[nb_input - 1].get_darkest_secret() << "\n"<< std::endl;
}
