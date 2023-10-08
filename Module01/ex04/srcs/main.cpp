#include <iostream>
#include <fstream>

void    modif_line(std::string *my_line, std::string old_str, std::string new_str){
    size_t pos;

    pos = my_line->find(old_str);
    while (pos != std::string::npos){
        my_line->erase(pos, old_str.length());
        my_line->insert(pos, new_str);
        pos = my_line->find(old_str);
    }
}

void    read_and_modify(std::ifstream &infile, std::string filename,std::string old_str, std::string new_str){
    std::string     line_infile;
    std::ofstream   outfile;

    if (old_str.empty()){
        std::cout << "Invalid String" << std::endl;
        return ;
    }

    outfile.open((filename + ".replace").c_str(), std::ofstream::out);
    if (outfile){
        while (getline(infile, line_infile)){
            modif_line(&line_infile, old_str, new_str);
            if (!line_infile.empty())
                outfile << line_infile << std::endl;
            line_infile.clear();
        }
        outfile.close();
    }
    else
        std::cout << "Couldn't open the " << filename <<"+replace file" << std::endl;
    infile.close();
}

void    launch_program(char **argv){
    std::ifstream infile(argv[1], std::fstream::in);

    if (infile)
        read_and_modify(infile, argv[1], argv[2], argv[3]);
    else
        std::cout << "Couldn't open the " << argv[1] << " file" << std::endl;
}

int main(int argc, char **argv){
    if (argc - 1 > 3)
        std::cout << "too many arguments !!!" << std::endl;
    else if (argc - 1 < 3)
        std::cout << "program required 3 arguments <filename> <old_string> <new_string>!!!" << std::endl;
    else
        launch_program(argv);
    return (0);
}