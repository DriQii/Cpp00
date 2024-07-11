#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"
#include <cstdlib>

struct contact_list
{
	Contact			contact;
	contact_list	*next;
};


class PhoneBook
{

public:
	PhoneBook(void);
	~PhoneBook(void);

	void	add_contact();
	void	search();

private:

	int		_nb_contact;
	Contact	_contact[8];

	int	_request_user_index();
};

#endif
