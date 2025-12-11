#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "contact.hpp"

class PhoneBook {
	private:
		Contact	ArrOfCon[8];
		int		index;
	public:
		void	add();
		void	search();
		PhoneBook();
};

#endif