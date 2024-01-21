#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <iostream>
#include <algorithm>

class Span
{
	public:
		Span(unsigned int N);
		Span(const Span &src);
		Span&	operator=(const Span &src);
		~Span();
		void	addNumber(unsigned int N);
		void	addNumberRange(unsigned int begin, unsigned int end);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		class SpanIsFull : public std::exception{
			public:
				const char*	what() const throw();
		};
		class NoDistanceFind : public std::exception{
			public:
				const char*	what() const throw();
		};
		class WrongRangeOfNumber : public std::exception{
			public:
				const char*	what() const throw();
		};
	private:
		Span(void);
		unsigned int	_N;
		std::vector<unsigned int>		_tab;
};

#endif