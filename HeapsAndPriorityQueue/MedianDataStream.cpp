#PRIORITY QUEUES

class MedianFinder {
public:
    priority_queue<int> max_heap; 
    priority_queue<int, vector<int>, greater<int>> min_heap; 

    MedianFinder() {
    }

    void addNum(int num) {
        max_heap.push(num);
        min_heap.push(max_heap.top());
        max_heap.pop();

        if (max_heap.size() < min_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    double findMedian() {
        if (max_heap.size() == min_heap.size()) {
            return (max_heap.top() + min_heap.top()) / 2.0;
        } else {
            return max_heap.top();
        }
    }
};




#BASIC ENTER SORT
class MedianFinder {
public:
    vector<int> solution;
    MedianFinder() {
       
    }
    
    void addNum(int num) {
        solution.push_back(num);
        sort(solution.begin(),solution.end());
    }
    
    double findMedian() {
    int size = solution.size();
    if (size == 0) {
        return 0.0; 
    }
    if (size % 2 == 0) {
        return (solution[size / 2] + solution[size / 2 - 1]) / 2.0;
    } else {
        return solution[size / 2];
    }
}

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
