#include <iostream>
#include "../includes/Array.hpp"
#include <cstring>

int	main(){

	Array<int>	Test1(5);
	Array<int>	Test1Copy(Test1);
	
	for (int i = 0; i < 5; i++){
		Test1[i] = i  + 1;
	}

	std::cout << "-------------------Modify Test1--------------------" << std::endl ;
	std::cout << "Value of Test1[0] : " << Test1[0] << std::endl;
	std::cout << "Value of Test1Copy[0] : " << Test1Copy[0] << std::endl;
	Test1[0] = 10;
	std::cout << "Modification DONE" << std::endl ;
	std::cout << "Value of Test1[0] : " << Test1[0] << std::endl;
	std::cout << "Value of Test1Copy[0] : " << Test1Copy[0] << std::endl;
	std::cout << "-------------------Modify Test2--------------------" << std::endl ;
	Array<int>	Test1Copy2 = Test1;
	std::cout << "Value of Test1[0] : " << Test1[0] << std::endl;
	std::cout << "Value of Test1Copy2[0] : " << Test1Copy2[0] << std::endl;
	Test1[0] = 20;
	std::cout << "Modification DONE" << std::endl ;
	std::cout << "Value of Test1[0] : " << Test1[0] << std::endl;
	std::cout << "Value of Test1Copy2[0] : " << Test1Copy2[0] << std::endl;

	std::cout << "-------------------Size Method test--------------------" << std::endl ;
	Array<char>	teststr;

	std::cout << "size teststr : "<< teststr.size() << std::endl;
	std::cout << "size test1 : "<< Test1.size() << std::endl;
	std::cout << "-------------------Index Invalid Test--------------------" << std::endl ;
	try{
		std::cout << "size test1 : "<< Test1[-1] << std::endl;
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		std::cout << "size teststr1 : "<< teststr[0] << std::endl;
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------Test With type string--------------------" << std::endl ;
	Array<char>	teststr1(10);

	for (int j = 0; j < 10; j++){
		teststr1[j] = 'j';
	}
	std::cout << teststr1[0] << std::endl;
	std::cout << teststr1[1] << std::endl;
	std::cout << teststr1[2] << std::endl;
	std::cout << teststr1[3] << std::endl;

	std::cout << "Create teststr2 with teststr" << std::endl;
	Array<char> teststr2 = teststr1;
	std::cout << teststr2[0] << std::endl;
	std::cout << teststr2[1] << std::endl;
	std::cout << teststr2[2] << std::endl;
	std::cout << teststr2[3] << std::endl;

	teststr1[0] = 'P';
	std::cout << " Modify teststr1[0] teststr-------------" << std::endl;
	std::cout << teststr1[0] << std::endl;
	std::cout << teststr1[1] << std::endl;
	std::cout << "teststr2-------------" << std::endl;
	std::cout << teststr2[0] << std::endl;
	std::cout << teststr2[1] << std::endl;
	return 0;
}