#include "Contact.hpp"

void	Contact::_add_user_entry(std::string *str, const char* prompt, int state)
{
	std::cout << prompt;
	std::getline(std::cin, *str);
	if (state == 1)
	{
		while (_check_entry(*str) || str->size() == 0 || _check_digit(*str))
		{
			std::cout << "Enter one word without space , tab or newline please" << std::endl;
			std::cout << prompt;
			std::getline(std::cin, *str);
		}
	}
	if (state == 0)
	{
		while (str->size() == 0)
		{
			std::cout << "Enter at least one character" << std::endl;
			std::cout << prompt;
			std::getline(std::cin, *str);
		}
	}
}

int	Contact::_check_entry(std::string str)
{
	if (str.find_first_of(' ') != std::string::npos
		|| str.find_first_of('\t') != std::string::npos
		|| str.find_first_of('\n') != std::string::npos)
			return (1);
	return(0);
}
int	Contact::_check_digit(std::string str)
{
	for(int i = 0; str[i]; i++)
	{
		if (isdigit(str[i]))
			return(1);
	}
	return (0);
}

int	Contact::_check_phone(std::string str)
{
	for(int i = 0; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

void	Contact::assign_information(void)
{
	std::cout << "\n";
	_add_user_entry(&this->_first_name, "First name : ", 1);
	_add_user_entry(&this->_last_name, "Last name : ", 1);
	_add_user_entry(&this->_nickname, "Nickname : ", 0);
	_add_user_entry(&this->_phone_number, "Phone numer : ", 0);
	while (this->_phone_number.size() != 10 || !this->_check_phone(this->_phone_number))
	{
		std::cout << "Phone number need 10 numeric characther" << std::endl;
		_add_user_entry(&this->_phone_number, "Phone numer : ", 0);
	}
	_add_user_entry(&this->_darkest_secret, "Darkest secret : ", 0);
	std::cout << "\n";
}

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

std::string	Contact::get_first_name(void) const
{
	return(this->_first_name);
}

std::string	Contact::get_last_name(void) const
{
	return(this->_last_name);
}

std::string	Contact::get_nickname(void) const
{
	return(this->_nickname);
}

std::string	Contact::get_phone_number(void) const
{
	return(this->_phone_number);
}

std::string	Contact::get_darkest_secret(void) const
{
	return(this->_darkest_secret);
}


