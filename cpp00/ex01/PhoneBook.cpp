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
        getline(std::cin, input);
        ArrOfCon[index].setFirstName(input);
    }
    input = "";
    while (input == "")
    {
        std::cout << "Enter Last Name: ";
        getline(std::cin, input);
        ArrOfCon[index].setLastName(input);
    }
    input = "";
    while (input == "")
    {
        std::cout << "Enter Nickname: ";
        getline(std::cin, input);
        ArrOfCon[index].setNickName(input);
    }
    input = "";
    while (input == "")
    {
        std::cout << "Enter Phone Number: ";
        getline(std::cin, input);
        ArrOfCon[index].setPhoneNumber(input);
    }
    input = "";
    while (input == "")
    {
        std::cout << "Enter Darkest Secret: ";
        getline(std::cin, input);
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
	std::cout << "Enter Index: ";
	getline(std::cin, index);
	i = std::atoi(index.c_str());
	while (i < 0 || i > 7)
	{
		std::cout << "Index Must Be Between 0 And 7.\nEnter Index: ";
		getline(std::cin, index);
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
