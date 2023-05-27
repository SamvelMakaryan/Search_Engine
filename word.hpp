#ifndef WORD_HPP_
#define WORD_HPP_
#include <string>
#include <fstream>
#include <cctype>

class Word {
public:
    Word(const std::string& s)
     : f("words_alpha.txt", std::ios::in)
    {
        m_word = s;
        normalize();
    }  
    Word(const Word& oth)
     : Word(oth.m_word) {}

    ~Word() {
        f.close();
    }
public:
    void setWord(const std::string& s) {
        m_word = s;
        normalize();
    }
    std::string getWord() const {
        return m_word;
    }
    bool operator==(const Word& oth) {
        return oth.m_word == m_word;
    }
    Word& operator=(const Word& oth) {
        m_word = oth.m_word;
        return *this;
    }
    bool operator<(const Word& oth) const {
        return m_word < oth.m_word;
    }
private:
    void normalize() {
        int i = 0;
        for (auto i = m_word.begin(); i != m_word.end();) {
            if (!std::isalpha(*i)) {
                m_word.erase(i);
            }
            else if (std::isupper(*i)) {
                *i = std::tolower(*i);
                ++i;
            }
            else {
                ++i;
            }
        }
        std::string normal_word = m_word;
        std::string cur;
        while (std::getline(f, cur)) {
            cur.pop_back();
            int size1 = cur.size();
            int size2 = m_word.size();
            int max = size1 > size2 ? size1 : size2;
            int min = size1 > size2 ? size2 : size1;
            if (max - min > 1) {
                continue;
            }
            int count = 0;

            std::string max_norm = size1 > size2 ? cur : m_word;
            std::string min_norm = size1 > size2 ? m_word : cur;
            for (int i = 0, j = 0; i < max && j < min && count < 2; ++i, ++j) {
                if ((max_norm[i] ^ min_norm[j] ) != 0) {
                    ++count;
                    if (max != min) {
                    --j;
                    }
                }
            }
            if ((max_norm[max - 1] ^ min_norm[min - 1]) != 0 && count < 2) {
                ++count;
            }
            if (count == 0) {
                return;
            }
            if (count > 1) {
                continue;
            }
            normal_word = cur;
        }
        m_word = normal_word;
    }
private:
    std::fstream f;
    std::string m_word;
};

#endif //WORD_HPP_