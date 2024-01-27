#include "../includes/easyfind.hpp"

int	main(){

	try{
		std::deque<int> numbers;

		for (int i = 0; i < 100; i++){
			numbers.push_back(i * (3 + i));
		}
		easyfind(numbers, 70);
		std::cout << "Occurence found" << std::endl;
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
	}

	try{
		std::vector<int> numbers;

		for (int i = 0; i < 100; i++){
			numbers.push_back(i * (2 + i));
		}
		
		easyfind(numbers, 56);
		std::cout << "Occurence found" << std::endl;
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
	}

	try{
		std::deque<char> numbers;

		for (int i = 0; i < 13; i++){
			numbers.push_back(i + 'F');
		}
		easyfind(numbers, 'I');
		std::cout << "Occurence found" << std::endl;
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
	}

	try{
		std::vector<char> numbers;

		for (int i = 0; i < 13; i++){
			numbers.push_back(i + 'F');
		}
		easyfind(numbers,'E');
		std::cout << "Occurence found" << std::endl;
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}