#ifndef TETX_HPP_
#define TETX_HPP_
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include "word.hpp"

class Text {
public:
    Text(const std::string& path)
     : path(path),
       f(path, std::ios::in)
    {
        std::string input;
       while (std::getline(f, input)) {
            std::stringstream spliting_words(input);
            std::string tmp_word;
            while (spliting_words >> tmp_word) {
                m_words.push_back(Word(tmp_word));
            }
       }
    }
    ~Text() {
        f.close();
    }
    void print() {
        for (auto i : m_words) {
            std::cout << i.getWord() << std::endl;
        }
    }
public:
    int find(const std::string& str) {
        for (int i = 0; i < m_words.size(); ++i) {
            if (m_words[i].getWord() == str) {
                return i;
            }
        }
        return -1;
    }
    Word getWord(int index) {
        return m_words[index];
    }
    int size() const {
        return m_words.size();
    }
private:
    std::vector<Word> m_words;
    std::fstream f;
    std::string path;
};

#endif //TETX_HPP_