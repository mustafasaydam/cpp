#include "./contact.hpp"

class PhoneBook
{
private:
    Contact _clients[8];
    int     _index;
public:
    PhoneBook(void);
    ~PhoneBook(void);
    bool	add_contact_to_phonebook(void);
    void    search_contact(void);
};