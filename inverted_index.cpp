#include <unordered_map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "forward_list/Forward_List.hpp"

int main() {
    std::unordered_map<std::string, my::Forward_List<std::string>> index;
    std::fstream fin("db.txt", std::ios::in);
    std::string line;
    while (std::getline(fin, line)) {
        std::stringstream ss(line);
        std::string word;
        std::string filenames;
        std::getline(ss, word, ':');
        word.pop_back();
        std::getline(ss, filenames);
        std::string file;
        std::stringstream fs(filenames);
        while (std::getline(fs, file, ',')) {
            index[word].push_back(file);
        }
    }
    fin.close();
    while (true) {
        std::string s;
        std::cin >> s;
        for (auto i : index[s]) {
            std::cout << i << " ";
        }
    }
}