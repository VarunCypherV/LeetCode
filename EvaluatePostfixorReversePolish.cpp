class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack; 
        for (auto x : tokens) {
            if (x == "+" || x == "-" || x == "*" || x == "/") {
                int b = stack.top();
                stack.pop();
                int a = stack.top();
                stack.pop();
                if (x == "+") {
                    stack.push(a + b);
                } else if (x == "-") {
                    stack.push(a - b);
                } else if (x == "*") {
                    stack.push(a * b);
                } else if (x == "/") {
                    stack.push(a / b);
                }
            } else {
                stack.push(stoi(x));
            }
        }
        
        return stack.top();
    }
};
