#include "PhoneBook.hpp"

int main ()
{
	std::string	command;
	PhoneBook	MyPhone;

	while (true)
	{
		if (!getline(std::cin, command))
			exit (0);
		if (command == "ADD")
			MyPhone.add();
		else if (command == "SEARCH")
			MyPhone.search();
		else if (command == "EXIT")
			break ;	
	}
	return (0);
}
