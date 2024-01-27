#ifndef __RPN_HPP__
# define __RPN_HPP__

# include <iomanip>
# include <iostream>
# include <climits>
# include <fstream>
# include <sstream>
# include <stack>
# include <string>

class RPN
{
private:
	RPN( void );
	RPN( const RPN &srcOp );
	~RPN( void );

	RPN	&operator=( const RPN &srcOp );

	static void	parse( std::string operation, std::stack<int> &stack );
	static int	doOp( char op, std::stack<int> &stack );

public:
	static void	rpn( const std::string operation );
	
};

#endif