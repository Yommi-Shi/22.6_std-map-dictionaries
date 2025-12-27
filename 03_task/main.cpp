#include <iostream>
#include <map>
#include <string>

bool is_anagram(std::string str_1, std::string str_2) {
    if (str_1.length() != str_2.length()) {
        return false;
    }
    std::map<char, int> char_count;
    for (char c : str_1) {
        ++char_count[c];
    }

    for (char c : str_2) {
        --char_count[c];
    }

    for (std::pair<char, int> p : char_count) {
        if (p.second != 0) {
            return false;
        }
    }
    return true;

}

int main() {
    std::cout << "===Anagrams===" << std::endl;

    std::string s1 = "listen";
    std::string s2 = "silent";

    if (is_anagram(s1, s2)) {
        std::cout << "This is an anagram.\n";
    } else {
        std::cout << "This is not an anagram.\n";
    }
}
