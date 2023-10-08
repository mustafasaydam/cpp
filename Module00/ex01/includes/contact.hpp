#include <iostream>
#include <iomanip>
class Contact
{
	private:
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_phonenumber;
		std::string	_darkest_secret;
	public:
		Contact(void);
		~Contact(void);

		bool	add_new_contact(void);
		void	print_contacts(int index);
		bool    print_full_info();
};
