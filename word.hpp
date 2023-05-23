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
            if (cur == m_word) {
                return;
            }
            int size1 = cur.size();
            int size2 = m_word.size();
            int missed = 0;
            if (size1 == size2) {
                for (int i = 0; i < size1; ++i) {
                    if (cur[i] != m_word[i]) {
                        if (missed > 1) {
                            break;
                        }
                        ++missed;
                    }
                }
                if (missed <= 1) {
                    normal_word = cur;
                }
                continue;
            }
            int min;
            int max;
            if (size1 > size2) {
                min = size2;
                max = size1;
            }
            else {
                min = size1;
                max = size2;
            }
            if (max - min != 1) {
                continue;
            }
            char tmp = 0;
            for (int i = 0; i < min; ++i) {
                tmp ^= cur[i];
                tmp ^= m_word[i]; 
            }
            tmp ^= max == size1 ? cur.back() : m_word.back(); 
            std::string normal = max == size1 ? cur : m_word;
            std::string oth_normal = max == size1 ? m_word : cur;
            int index = -1;
            for (int i = 0; i < normal.size(); ++i) {
                if (tmp == normal[i]) {
                    index = i;
                    break;
                }
            }
            if (index == -1) {
                continue;
            }   
            oth_normal.insert(oth_normal.begin() + index, tmp);
            if (oth_normal == normal) {
                normal_word = normal;
            }
        }
        m_word = normal_word;
    }
private:
    std::fstream f;
    std::string m_word;
};

#endif //WORD_HPP_