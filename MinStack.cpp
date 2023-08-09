// Min Stack




// using vector
class MinStack {

private:     
    vector<int> stack;
public:
    MinStack() {
  
    }
    
    void push(int val) {
        stack.push_back(val);
    }
    
    void pop() {
         stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
         return *min_element(stack.begin(),stack.end());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
