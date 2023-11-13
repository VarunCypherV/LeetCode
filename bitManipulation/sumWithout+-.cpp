class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0) {
            
            int sum_without_carry = a ^ b; //sum without carry is xor
            int carry = (a & b) << 1; //carry is & and we left shift cuz carry comes 1 digit left
            //we update and keep adding carry to sum until no carry
            a = sum_without_carry;
            b = carry;
        }
        return a;
    }
};
