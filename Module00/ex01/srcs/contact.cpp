#include "../includes/contact.hpp"

Contact::Contact(void){
	return ;
}

Contact::~Contact(void){
	return ;
}

static bool    is_name(std::string name){
	for (unsigned int  i = 0; i < name.length(); ++i){
		if (!std::isalpha(name[i]))
			return (false);
	}
	return (true);
}

static bool    is_phonenumber(std::string name){
	if (name.length() != 10)
		return (false);
	for (unsigned int  i = 0; i < name.length(); ++i){
		if (!std::isdigit(name[i]))
			return (false);
	}
	return (true);
}

static std::string fill_field(std::string sentence_field, int type_field){
	std::string info;

	std::cout << sentence_field;
	std::getline(std::cin, info);
	if (std::cin.eof()){
		std::cout << "^D" << std::endl;
		return("");
	}
	while (info.length() == 0 || ((type_field == 0 || type_field == 1 ) && !is_name(info)) || ((type_field == 3 && !is_phonenumber(info)))){
		if (info.length() == 0)
			std::cout << "You need to fill the field" << std::endl;
		else
			std::cout << "Incorrect Format" << std::endl;
		std::cout << sentence_field;
		std::getline(std::cin, info);
		if (std::cin.eof()){
			std::cout << "^D" << std::endl;
			return("");
		}
	}
	return (info);
}

std::string cut_string(std::string value){
	if (value.length() > 10)
		return (value.substr(0, 9) + ".");
	return (value);
}

bool    Contact::print_full_info(void){
	if (this->_firstname.empty())
		return (false);
	std::cout << "Information of Contact \n";
	std::cout << "First name : " << this->_firstname << std::endl;
	std::cout << "Last name : " << this->_lastname << std::endl;
	std::cout << "Nick name : " << this->_nickname << std::endl;
	std::cout << "Phone Number : " << this->_phonenumber << std::endl;
	std::cout << "Darkest Secret : " << this->_darkest_secret << std::endl;
	return (true);
}

void    Contact::print_contacts(int index){
	std::string index_value;
	if (this->_firstname.empty())
		return;
	index_value = index + '0'; 
	std::cout << "|" << std::setw(10) << cut_string(index_value) << "|" << std::setw(10) << cut_string(this->_firstname) << "|" << std::setw(10) << cut_string(this->_lastname)  << "|" << std::setw(10) << cut_string(this->_nickname) << "|" << std::endl;
}

bool	Contact::add_new_contact(void){
	this->_firstname = fill_field("Enter firstname : ", 0);
	if (this->_firstname == "")
		return(false);
	this->_lastname = fill_field("Enter lastname : ", 1);
	if (this->_firstname == "")
		return(false);
	this->_nickname = fill_field("Enter nickname : ", 2);
	if (this->_firstname == "")
		return(false);
	this->_phonenumber = fill_field("Enter phonenumber (without starting with 0) : ", 3);
	if (this->_firstname == "")
		return(false);
	this->_darkest_secret = fill_field("Enter darkest secret : ", 2);
	if (this->_firstname == "")
		return(false);
	return (true);
}
