#include "../includes/MutantStack.hpp"

int	main(){
	{
		std::cout << "-----------------------TEST EXAMPLE----------------------------" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout<< "Stack size = " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(9);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::cout << "check copy" << std::endl;
		std::stack<int> s(mstack);
		std::stack<int> a = s;
		std::cout << &a << " "<< &s << " " <<  &mstack<< std::endl;
		mstack.push(1457);
		std::cout << mstack.top() << " " << s.top() << " " << a.top() << std::endl;
		s.push(5789);
		std::cout << mstack.top() << " " << s.top() << " " << a.top() << std::endl;
	}
	{
		std::cout << "-----------------------MY TEST----------------------------" << std::endl;
		MutantStack<int> test;

		for (int i = 0; i < 100; i++){
			test.push(i * (3 + i));
		}
		std::cout << "TOP = "<< test.top() << std::endl;
		for (MutantStack<int>::iterator it = test.begin(); it != test.end(); it++){
			std::cout << *it << std::endl;
		}
	}
	return (0);
}