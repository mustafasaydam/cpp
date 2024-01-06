#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void	print_elem(const T &elem){
	std::cout << elem << std::endl;
}

template <typename T>
void	iter(const T* address, unsigned int size, void (*function)(const T&)){
	for (unsigned int i = 0; i < size; i++){
		function(address[i]);
	}
}

template <typename T>
void	iter(T* address, unsigned int size, void (*function)(T&)){
	for (unsigned int i = 0; i < size; i++){
		function(address[i]);
	}
}

#endif