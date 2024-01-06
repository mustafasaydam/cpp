#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <exception>

template<typename T>
class Array
{
	private:
		T*				_tab;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& src);
		Array&	operator=(const Array& src);
		unsigned int	size();
		T&	operator[](int index);
		~Array();
};

template <typename T>
Array<T>::Array(){
	this->_tab = NULL;
	this->_size = 0;
};

template <typename T>
Array<T>::Array(unsigned int n){
	if (n > 0)
		this->_tab = new T[n];
	else
		this->_tab = NULL;
	this->_size = n;
	for (unsigned int i = 0; i < n; i++){
		this->_tab[i] = 0;
	}
};

template <typename T>
Array<T>::Array(const Array& src){
	this->_size = src._size;
	this->_tab = new T[src._size];
	for (unsigned int i = 0; i < src._size; i++){
		this->_tab[i] = src._tab[i];
	}
	return;
};

template <typename T>
Array<T>::~Array(){
	if (this->_tab)
		delete [] _tab;
	return;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& src){
	this->_size = src._size;
	if (this->_tab)
		delete (this->_tab);
	this->_tab = new T[src._size];
	for (unsigned int i = 0; i < src._size; i++){
		this->_tab[i] = src._tab[i];
	}
	return (*this);
}

template <typename T>
unsigned int	Array<T>::size(){
	const unsigned int value = this->_size;
	return (value);
}

class InvalidIndexException : public std::exception {
	public:
		virtual const char* what()const throw() {
			return ("Invalid index");
		}
};

template <typename T>
T&	Array<T>::operator[](int index){
	if (index < 0 || (unsigned int)index >= this->_size)
		throw InvalidIndexException();
	return (this->_tab[index]);
}

#endif