#include <vector>

class Solution {
public:
    int lastStoneWeight( vector<int>& stones) {
        vector<int> maxHeap;
        
        for (int stone : stones) {
            maxHeap.push_back(stone);
            heapifyUp(maxHeap);
        }
        
        while (maxHeap.size() >= 2) {
            int firstStone = extractMax(maxHeap);
            int secondStone = extractMax(maxHeap);
            int remainingStone = firstStone - secondStone;
            if (remainingStone > 0) {
                maxHeap.push_back(remainingStone);
                heapifyUp(maxHeap);
            }
        }
        if (maxHeap.empty()) {
            return 0;
        } else {
            return maxHeap[0];
        }
    }

    
    int extractMax( vector<int>& maxHeap) {
        int maxElement = maxHeap[0];
        maxHeap[0] = maxHeap.back();
        maxHeap.pop_back();
        heapifyDown(maxHeap);
        return maxElement;
    }


    void heapifyUp(vector<int>& maxHeap) {
        int index = maxHeap.size() - 1;
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (maxHeap[index] > maxHeap[parentIndex]) {
                 swap(maxHeap[index], maxHeap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown(vector<int>& maxHeap) {
        int index = 0;
        int size = maxHeap.size();
        while (true) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < size && maxHeap[leftChild] > maxHeap[largest]) {
                largest = leftChild;
            }

            if (rightChild < size && maxHeap[rightChild] > maxHeap[largest]) {
                largest = rightChild;
            }

            if (largest != index) {
                swap(maxHeap[index], maxHeap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }
};
