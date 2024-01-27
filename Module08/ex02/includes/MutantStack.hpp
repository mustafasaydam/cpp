#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H
#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack<T>(){};
		MutantStack<T>(const MutantStack<T> &src){
			*this = src;
		};
		virtual ~MutantStack<T>(){};
		MutantStack<T>	operator=(const MutantStack<T> &src){
			return std::stack<T>::operator=(src);
		}
		typedef typename MutantStack<T>::container_type container_type;
		typedef typename container_type::iterator iterator;
		typedef typename container_type::const_iterator const_iterator;
		typedef typename container_type::reverse_iterator reverse_iterator;
		typedef typename container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin(){return (this->c.begin());}
		iterator end(){return (this->c.end());}
		const_iterator begin() const{return (this->c.cbegin());}
		const_iterator end() const{return (this->c.cend());}
		reverse_iterator rbegin(){return (this->c.rbegin());}
		reverse_iterator rend(){return (this->c.rend());}
		const_reverse_iterator rbegin() const{return (this->c.rbegin());}
		const_reverse_iterator rend() const{return (this->c.rend());}
	private:
};

#endif