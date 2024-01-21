#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <algorithm>

class easyfind
{
	public:

};

class	NoOccurenceException : public std::exception{
	public:
		virtual const char*	what() const throw (){
			return "No Occurence Found";
		}
};

template <typename T>
typename T::iterator	easyfind(T container, int integer){
	typename T::iterator it;

	it = find(container.begin(), container.end(), integer);
	if (it == container.end())
		throw NoOccurenceException();
	return (it);
}

#endif