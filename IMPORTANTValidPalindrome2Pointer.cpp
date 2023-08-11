

// my soln
class Solution {
public:

    static bool isalnumz(char c){
        return !isalnum(c);
    }

    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        s.erase(remove_if(s.begin(), s.end(), isalnumz), s.end());
        int sptr = 0;
        int eptr = s.size() - 1;
        while (sptr < eptr) {
            if (s[sptr] != s[eptr]) {
                return false;
            }
            sptr++;
            eptr--;
        }
        return true;
    }
};
