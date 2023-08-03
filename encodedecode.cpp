#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    string encode(const vector<string>& strs) {
        std::string en = "";
        for (const auto& x : strs) {
            if (x != strs.back()) {
                en = en + x + ":;";
            } else {
                en = en + x;
            }
        }
        return en;
    }

    vector<string> decode(const string& str) {
        std::string temp = "";
        vector<string> result;
        for (size_t x = 0; x < str.length(); x++) {
            if (str[x] != ':' && str[x + 1] != ';') {
                temp += str[x];
            } else {
                result.push_back(temp);
                temp = "";
                x++;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> input = {"apple", "banana", "orange"};
    string encoded = solution.encode(input);
    cout << "Encoded: " << encoded << std::endl;
    svector<string> decoded = solution.decode(encoded);
    cout << "Decoded: ";
    for (const auto& word : decoded) {
        std::cout << word << " ";
    }
    return 0;
}
