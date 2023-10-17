#PRIORITY QUEUES
class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int n;

public:
    MedianFinder() {
        n = 0;
    }

    void addNum(int num) {
        if (n % 2 == 0) {
            if (n == 0) {
                maxHeap.push(num);
            } else {
                int topOfMinHeap = minHeap.top();
                if (num >= topOfMinHeap) {
                    maxHeap.push(topOfMinHeap);
                    minHeap.pop();
                    minHeap.push(num);
                } else {
                    maxHeap.push(num);
                }
            }
        } else {
            int topOfMaxHeap = maxHeap.top();
            if (topOfMaxHeap < num) {
                minHeap.push(num);
            } else {
                maxHeap.pop();
                maxHeap.push(num);
                minHeap.push(topOfMaxHeap);
            }
        }
        n++;
    }

    double findMedian() {
        if (n % 2 == 1)
            return maxHeap.top();
        return (static_cast<double>(maxHeap.top() + minHeap.top())) / 2;
    }
};




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


#RED BLACK TREE

class MedianFinder {
public:
    struct TreeNode {
        int val;
        int count;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int x) : val(x), count(1), left(nullptr), right(nullptr) {}
    };

    TreeNode* root = nullptr;
    int totalElements = 0;

    void insert(TreeNode*& node, int val) {
        if (!node) {
            node = new TreeNode(val);
        } else {
            node->count++;
            if (val < node->val) {
                insert(node->left, val);
            } else {
                insert(node->right, val);
            }
        }
    }

    void addNum(int num) {
        insert(root, num);
        totalElements++;
    }

    double findKth(TreeNode* node, int k) {
        if (!node) {
            return 0.0;
        }

        int leftCount = node->left ? node->left->count : 0;

        if (k == leftCount + 1) {
            return static_cast<double>(node->val);
        } else if (k <= leftCount) {
            return findKth(node->left, k);
        } else {
            return findKth(node->right, k - leftCount - 1);
        }
    }

    double findMedian() {
        if (totalElements % 2 == 1) {
            return findKth(root, (totalElements + 1) / 2);
        } else {
            return (findKth(root, totalElements / 2) + findKth(root, totalElements / 2 + 1)) / 2.0;
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
