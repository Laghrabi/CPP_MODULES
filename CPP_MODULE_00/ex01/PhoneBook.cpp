#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    index = 0;
}
void    PhoneBook::add()
{
    std::string input;

    input = "";
    while (input == "")
    {
        std::cout << "Enter First Name: ";
        if (!getline(std::cin, input))
			exit(0);
        ArrOfCon[index].setFirstName(input);
    }
    input = "";
    while (input == "")
    {
        std::cout << "Enter Last Name: ";
        if (!getline(std::cin, input))
			exit(0);
        ArrOfCon[index].setLastName(input);
    }
    input = "";
    while (input == "")
    {
        std::cout << "Enter Nickname: ";
        if (!getline(std::cin, input))
			exit(0);
        ArrOfCon[index].setNickName(input);
    }
    input = "";
    while (input == "")
    {
        std::cout << "Enter Phone Number: ";
        if (!getline(std::cin, input))
			exit(0);
        ArrOfCon[index].setPhoneNumber(input);
    }
    input = "";
    while (input == "")
    {
        std::cout << "Enter Darkest Secret: ";
        if (!getline(std::cin, input))
			exit(0);
        ArrOfCon[index].setDarkestSecret(input);
    }
    index++;
    index %= 8;
}

void	PhoneBook::search()
{
	int			i;
	std::string	index;

	i = 0;
	while (i < 8 && ArrOfCon[i].getFirstName() != "")
	{
		std::cout << "|" << std::setw(10);
		std::cout << i << "|" << std::setw(10);
		if (ArrOfCon[i].getFirstName().length() < 10)
			std::cout << ArrOfCon[i].getFirstName();
		else
			std::cout << ArrOfCon[i].getFirstName().substr(0, 9) << ".";
		std::cout << "|" << std::setw(10);
		if (ArrOfCon[i].getLastName().length() < 10)
			std::cout << ArrOfCon[i].getLastName();
		else
			std::cout << ArrOfCon[i].getLastName().substr(0, 9) << ".";
		std::cout << "|" << std::setw(10);
		if (ArrOfCon[i].getNickName().length() < 10)
			std::cout << ArrOfCon[i].getNickName();
		else
			std::cout << ArrOfCon[i].getNickName().substr(0, 9) << ".";
		std::cout << "|";
		std::cout << std::endl;
		i++;
	}
	index = "";
	while (index[0] < 48 || index[0] > 57)
	{
		std::cout << "Enter Index: ";
		if (!getline(std::cin, index))
			exit(0);
		std::cout << "Index must be a digit." << std::endl;
	}
	i = std::atoi(index.c_str());
	while (i < 0 || i > 7)
	{
		std::cout << "Index Must Be Between 0 And 7.\nEnter Index: ";
		if (!getline(std::cin, index))
			exit(0);
		i = std::atoi(index.c_str());
	}
	if (ArrOfCon[i].getFirstName() == "")
		std::cout << "Contact Doesn't Exist\n";
	else
	{
		std::cout << "FirstName: " << ArrOfCon[i].getFirstName() << std::endl;
		std::cout << "LastName: " << ArrOfCon[i].getLastName() << std::endl;
		std::cout << "NickName: " << ArrOfCon[i].getNickName() << std::endl;
		std::cout << "PhoneNumber: " << ArrOfCon[i].getPhoneNumber() << std::endl;
		std::cout << "DarkestSecret: " << ArrOfCon[i].getDarkestSecret() << std::endl;
	}
}
