#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

class Contact {
	private:
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string PhoneNumber;
		std::string DarkestSecret;
	public:
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickName();
		std::string	getPhoneNumber();
		std::string	getDarkestSecret();
		void		setFirstName(std::string input);
		void		setLastName(std::string input);
		void		setNickName(std::string input);
		void		setPhoneNumber(std::string input);
		void		setDarkestSecret(std::string input);
};

#endif