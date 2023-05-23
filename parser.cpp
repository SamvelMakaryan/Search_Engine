#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <set>
#include "word.hpp"
#include "text.hpp"

int main() {
    Text file1("1.txt");
    Text file2("2.txt");
    std::fstream new_file("db.txt", std::ios::out);
    std::string tmp;
    std::set<Word> words;
    for (int i = 0; i < file1.size(); ++i) {
        words.insert(file1.getWord(i));
    }
    for (int i = 0; i < file2.size(); ++i) {
        words.insert(file2.getWord(i));
    }
    for (auto i = words.begin(); i != words.end(); ++i) {
        std::string current = (*i).getWord();
        bool contains1 = (file1.find((*i).getWord()) != -1);
        current += " :";
        if (contains1) {
            current += "1";
        }
        bool contains2 = (file2.find((*i).getWord()) != -1);
        if (contains1 && contains2) {
            current += ",";
        }
        if (contains2) {
            current += "2";
        }
        new_file << current << std::endl;
   }
    new_file.close();
}
