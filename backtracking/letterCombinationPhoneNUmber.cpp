class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> map;
        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";

        vector<string> result;
        string current;
        if (digits.empty()) {
            return result;
        } 
        backtrack(result, current, digits, map, 0);
        return result;
    }

    void backtrack(vector<string>& result, string& current, string& digits, unordered_map<char, string>& map, int index) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        char digit = digits[index];
        string& letters = map.at(digit);
        for (char letter : letters) {
            current.push_back(letter);
            backtrack(result, current, digits, map, index + 1);
            current.pop_back();
        }
    }
};
