#include <iostream>

int main(int argc, char ** argv){
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else{
        for (int i = 1; i < argc; ++i){
            std::string  word(argv[i]);

            for (unsigned int j = 0; j < word.length(); ++j){
                word[j] = toupper(word[j]);
            }
            std::cout << word;
        }
        std::cout << std::endl;
    }
    return (0);
}