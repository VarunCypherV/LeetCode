class Solution {

public:
    vector<int> minHeap;
    int add(int val,int k) {
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
    int findKthLargest(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            add(nums[i],k);
        }
        return minHeap[0];
    }
};
