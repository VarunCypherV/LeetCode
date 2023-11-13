class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            // Counting the number of set bits in i by using the result of i / 2
            result[i] = result[i >> 1] + (i & 1);
        }
        return result;
    }
};

// Suppose n = 5, and we want to generate an array containing the count of set bits for each number from 0 to 5.
// Initialize result array: [0, 0, 0, 0, 0, 0]
// Start the loop from i = 1:

// a. For i = 1:
// i >> 1 is 0  (right shifting 1 by 1), and (i & 1) is 1.
// So, result[1] = result[0] + 1 = 0 + 1 = 1.
// b. For i = 2:

// i >> 1 is 1 (right shifting 2 by 1), and (i & 1) is 0.
// So, result[2] = result[1] + 0 = 1 + 0 = 1.
// c. For i = 3:

// i >> 1 is 1 (right shifting 3 by 1), and (i & 1) is 1.
// So, result[3] = result[1] + 1 = 1 + 1 = 2.
// d. For i = 4:

// i >> 1 is 2 (right shifting 4 by 1), and (i & 1) is 0.
// So, result[4] = result[2] + 0 = 1 + 0 = 1.
// e. For i = 5:

// i >> 1 is 2 (right shifting 5 by 1), and (i & 1) is 1.
// So, result[5] = result[2] + 1 = 1 + 1 = 2.
// Final result array: [0, 1, 1, 2, 1, 2]