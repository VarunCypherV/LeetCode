class Solution {
public:
    
bool checkValidString(string s) {
    int minOpen = 0;
    int maxOpen = 0;
    for (char c : s) {
        if (c == '(') {
            minOpen++;
            maxOpen++;
        } else if (c == ')') {
            minOpen = max(0, minOpen - 1); 
            maxOpen--;
        } else if (c == '*') {
            minOpen = max(0, minOpen - 1); 
            maxOpen++;  // Treat '*' as empty string or  parentheses if >0 we arent returning false so extr * can be there no worries
        }
        if (maxOpen < 0) {
            return false; // If the maximum open parentheses count becomes negative, it's invalid.
        }
    }
    return minOpen == 0; // The string is valid if the minimum open parentheses count is 0.
}


};