#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cctype>

class Contact{

public:

	Contact(void);
	~Contact(void);

	std::string	get_first_name(void) const;
	std::string	get_last_name(void) const;
	std::string	get_nickname(void) const;
	std::string	get_phone_number(void) const;
	std::string	get_darkest_secret(void) const;

	void		assign_information();

private:

	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_darkest_secret;

	int		_check_digit(std::string str);
	int		_check_entry(std::string str);
	int		_check_phone(std::string str);
	void	_add_user_entry(std::string *str, const char* prompt, int state);
};


#endif
