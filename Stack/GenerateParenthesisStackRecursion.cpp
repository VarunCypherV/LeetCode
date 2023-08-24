class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesisHelper(result, "", 0, 0, n);
        return result;
    }

    void generateParenthesisHelper(vector<string>& result, string current, int openCount, int closeCount, int n) {
        if (current.size() == 2 * n) {
            result.push_back(current);
            return;
        }

        if (openCount < n) {
            generateParenthesisHelper(result, current + '(', openCount + 1, closeCount, n);
        }

        if (closeCount < openCount) {
            generateParenthesisHelper(result, current + ')', openCount, closeCount + 1, n);
        }
    }
};
