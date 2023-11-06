class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        backtrack(result, current, s, 0);
        return result;
    }

private:
    void backtrack(vector<vector<string>>& result, vector<string>& current, string& s, int start) {
        if (start == s.length()) {
            result.push_back(current);
            return;
        }

        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                current.push_back(s.substr(start, end - start + 1));
                backtrack(result, current, s, end + 1);
                current.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
