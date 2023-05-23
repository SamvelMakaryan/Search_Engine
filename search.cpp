#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::fstream f("db.txt", std::ios::in);
    std::string word;
    std::cout << "Input the word you want to search\n";
    std::cin >> word;
    std::string line;
    std::string filenames;
    bool found = false; 
    while (std::getline(f, line) && !found) {
        std::stringstream stream(line);
        std::string tmp;
        stream >> tmp;
        if (tmp == word) {
            stream >> tmp;
            int i = 1;
            while (tmp[i]) {
                if (tmp[i] == ',') {
                    ++i;
                    continue;
                }
                else {
                    found = true;
                    filenames += tmp[i];
                    filenames += " ";
                    ++i;
                }
            }
            
        } 
    }
    if (found) {
        std::cout << "Your word was found in file  " << filenames << std::endl;
    }
    else {
        std::cout << "Your word wasn't found\n";
    }
    f.close();
}