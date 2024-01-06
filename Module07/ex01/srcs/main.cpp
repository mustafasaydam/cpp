#include <iostream>
#include "../includes/iter.hpp"

int	main(){
	std::string tab[] = {"loop","prout", "caca"};
	::iter(tab, 3, print_elem);

	int tab1[] = {1,2, 3, 4, 5, 6};
	::iter(tab1, 6, print_elem);
	
	bool tab2[] = {true,false};
	::iter(tab2, 2, print_elem);

	return 0;
}