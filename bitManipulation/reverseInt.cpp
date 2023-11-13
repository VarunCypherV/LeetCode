class Solution {
public:
    int reverse(int x) {
        int MIN = -2147483648; //-2^31
        int MAX = 2147483647; //2^31 -1

        int res = 0;

        while (x) {
            int digit = x % 10;
            x = x / 10;
            //bit wise digit wise comparision
            //not looking at last digit as MAX or MIN/10 ,if greater than that then false
            // but if its exacatyl equal then we check last digit
            if (res > MAX / 10 || (res == MAX / 10 && digit > MAX % 10)) {
                return 0;
            }
            if (res < MIN / 10 || (res == MIN / 10 && digit < MIN % 10)) {
                return 0;
            }
            res = (res * 10) + digit;
        }
        return res;
    }
};
