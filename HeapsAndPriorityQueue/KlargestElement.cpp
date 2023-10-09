class KthLargest {
public:
    int k;
    vector<int> minHeap;

    KthLargest(int k, vector<int>& nums) {
        // Initialization
        this->k = k;
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        if (minHeap.size() < k) {
            minHeap.push_back(val); // Add at last, then heapify
            heapifyUp(minHeap.size() - 1);
        } else if (val > minHeap[0]) {
            // Add at root, then heapify
            minHeap[0] = val;
            heapifyDown(0);
        }
        return minHeap[0];
    }

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = i / 2;
            if (minHeap[i] < minHeap[parent]) {
                swap(minHeap[i], minHeap[parent]);
                i = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int i) {
        int n = minHeap.size();
        while (2 * i < n) {
            int left = 2 * i;
            int right = 2 * i + 1;
            int smallest = left;
            if (right < n && minHeap[right] < minHeap[left]) {
                smallest = right;
            }
            if (minHeap[i] > minHeap[smallest]) {
                swap(minHeap[i], minHeap[smallest]);
                i = smallest;
            } else {
                break;
            }
        }
    }
};
//JUST DIFFERENT PARENT RIGHT AND LEFT CHILD REPRESENTATION
class KthLargest {
public:
    int k;
    vector<int> minHeap;

    KthLargest(int k, vector<int>& nums) {
        //intialization
        this->k = k;
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        if (minHeap.size() < k) {
            minHeap.push_back(val); //add at last then heapify
            heapifyUp(minHeap.size() - 1);
        } else if (val > minHeap[0]) {
            //add at root then heapify
            minHeap[0] = val;
            heapifyDown(0);
        }
        return minHeap[0];
    }

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (minHeap[i] < minHeap[parent]) {
                swap(minHeap[i], minHeap[parent]);
                i = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int i) {
        int n = minHeap.size();
        while (2 * i + 1 < n) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = left;
            if (right < n && minHeap[right] < minHeap[left]) {
                smallest = right;
            }
            if (minHeap[i] > minHeap[smallest]) {
                swap(minHeap[i], minHeap[smallest]);
                i = smallest;
            } else {
                break;
            }
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
