// Min Stack
//stack stl
class MinStack {
private:
    stack<int> array;
    stack<int> minStack;

public:
    MinStack() {

    }

    void push(int val) {
        array.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (!array.empty()) {
            if (array.top() == minStack.top()) {
                minStack.pop();
            }
            array.pop();
        }
    }

    int top() {
        if (!array.empty()) {
            return array.top();
        }
        return -1;
    }

    int getMin() {
        if (!minStack.empty()) {
            return minStack.top();
        }
        return -1;
    }
};
//better optimization using min stack and array stack
class MinStack {

private:     
    int* array;
    int tops;
    int* min;
    int mintop;
public:
    MinStack() {
        tops=-1;
        mintop=-1;
        array = new int[10000];
        min= new int[10000];
    }
    
    void push(int val) {
        if( (mintop!=-1 && tops!=-1)&& (val<=*(min+mintop)) ) {
            mintop++;
            *(min+mintop)=val;
        }
        else if (mintop==-1){
            mintop++;
            *(min+mintop)=val;
        }
        tops++;
        *(array+tops)=val;

    }
    
    void pop() {
        cout << *(array+tops) <<" " << *(min+mintop)<<endl;
        if(( *(array+tops) == *(min+mintop)) && (mintop!=-1)){
            cout<< "accessed for array top" <<*(array+tops)<<endl;
            mintop--;
        }
         tops--;
    }
    
    int top() {
        return *(array+tops);
    }
    
    int getMin() {
        if(mintop!=-1){
            return *(min+mintop);
        }
        return 0;

    }
};
//Using array pointer
class MinStack {

private:     
    int* array;
    int tops;
public:
    MinStack() {
        tops=-1;
        array = new int[10000];
    }
    
    void push(int val) {
        tops++;
        *(array+tops)=val;
    }
    
    void pop() {
         tops--;
    }
    
    int top() {
        return *(array+tops);
    }
    
    int getMin() {
        int min=INT_MAX;
        for(int i=0;i<tops+1;i++){
            if(*(array+i)<min){
                min=*(array+i);
            }
        }
        return min;
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
