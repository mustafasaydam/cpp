#include "../includes/Span.hpp"

Span::Span(void)
{

}

Span::Span(unsigned int N) : _N(N)
{

}

Span::Span(const Span &src)
{
	*this = src;
}

Span::~Span()
{
	
}

Span&	Span::operator=(const Span &src){
	if (this == &src)
		return (*this);
	this->_N = src._N;
	this->_tab = src._tab;
	return (*this);
}

void	Span::addNumber(unsigned int N){
	try{
		if (this->_tab.size() == this->_N)
			throw SpanIsFull();
		this->_tab.push_back(N);
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

unsigned int	Span::shortestSpan(){
	if (this->_tab.size() <= 1)
		throw	NoDistanceFind();
	std::sort(this->_tab.begin(), this->_tab.end());
	unsigned int sht_dist = this->_tab.back() - this->_tab.front();
	for (std::vector<unsigned int>::iterator it = this->_tab.begin(); it != this->_tab.end(); it++){
		if ((it + 1) != this->_tab.end() && (*(it + 1) - *(it)) < sht_dist){
			sht_dist = (*(it + 1) - *(it));
		}
	}
	return (sht_dist);
}

unsigned int	Span::longestSpan(){
	if (this->_tab.size() <= 1)
		throw	NoDistanceFind();
	std::sort(this->_tab.begin(), this->_tab.end());
	return (this->_tab.back() - this->_tab.front());
}

void	Span::addNumberRange(unsigned int begin, unsigned int end){
	try{
		if (begin >= end)
			throw WrongRangeOfNumber();
		for (; begin < end ; begin++){
			addNumber(begin);
		}
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

const char*	Span::SpanIsFull::what() const throw(){
	return "The Span is full, cannot add another number!!!";
}

const char*	Span::NoDistanceFind::what() const throw(){
	return "No Distance Find";
}

const char*	Span::WrongRangeOfNumber::what() const throw(){
	return "Wrong Range of number";
}