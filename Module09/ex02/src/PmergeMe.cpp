#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() { }
PmergeMe::~PmergeMe() { }
PmergeMe::PmergeMe(const PmergeMe &other) {
	this->vector_order = other.vector_order;
	this->deque_order = other.deque_order;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		this->vector_order = other.vector_order;
		this->deque_order = other.deque_order;
	}
	return (*this);
}

void PmergeMe::intVectorPrinter() {
	for (std::vector<int>::iterator it = vector_order.begin(); it != vector_order.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	return ;
}

void PmergeMe::intDequePrinter() {
	for (std::deque<int>::iterator it = deque_order.begin(); it != deque_order.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	return ;
}

void PmergeMe::readInput(char **argv) {
	for (int i = 1; argv[i]; i++) {
		this->vector_order.push_back(std::atoi(argv[i]));
		this->deque_order.push_back(std::atoi(argv[i]));
	}
}

void PmergeMe::fordJohnsonSortWrapper() {
	std::cout << "Before: ";
	this->intVectorPrinter();
	clock_t start = clock();
	this->fordJohnsonSort(this->vector_order, 0, this->vector_order.size() - 1);
	clock_t stop = clock();
	std::cout << "After: ";
	this->intVectorPrinter();
	double duration = ((stop - start) / (double)CLOCKS_PER_SEC) * 1000000;
	std::cout << "Time to process a range of " << this->vector_order.size() << " elements with std::vector : " << duration << " us" << std::endl;

	std::cout << "Before: "; 
	this->intDequePrinter();
	start = clock();
	this->fordJohnsonSort(this->deque_order, 0, this->deque_order.size() - 1);
	stop = clock();
	std::cout << "After: ";
	this->intDequePrinter();
	duration = ((stop - start) / (double)CLOCKS_PER_SEC) * 1000000;
	std::cout << "Time to process a range of " << this->deque_order.size() << " elements with std::deque : " << duration << " us" << std::endl;
}

template<typename T>
void PmergeMe::fordJohnsonSort(T &lst, int startIndex, int endIndex) {
	int midIndex;

	if (startIndex != endIndex) {
		midIndex = (startIndex + endIndex) / 2;
		fordJohnsonSort(lst, startIndex, midIndex);
		fordJohnsonSort(lst, midIndex + 1, endIndex);
		mergeSublists(lst, startIndex, midIndex, endIndex);
	}
}

template<typename T>
void PmergeMe::mergeSublists(T &lst, int startIndex, int midIndex, int endIndex) {
	int leftIndex = startIndex;
	int rightIndex = midIndex + 1;
	int tempIndex = 0;
	std::vector<int> temp(endIndex - startIndex + 1);

	while ((leftIndex <= midIndex) && (rightIndex <= endIndex)) {
		if (lst[leftIndex] <= lst[rightIndex]) {
			temp[tempIndex] = lst[leftIndex];
			tempIndex++;
			leftIndex++;
		}
		else {
			temp[tempIndex] = lst[rightIndex];
			tempIndex++;
			rightIndex++;
		}
	}

	while (leftIndex <= midIndex)
		temp[tempIndex++] = lst[leftIndex++];

	while (rightIndex <= endIndex)
		temp[tempIndex++] = lst[rightIndex++];

	for (int p = 0; p < tempIndex; p++)
		lst[startIndex + p] = temp[p];
}