#include <vector>
#include <queue>

class KthLargest {
private:
    // Min-heap to store the k largest elements
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int k_size;

public:
    KthLargest(int k, std::vector<int>& nums) {
        k_size = k;
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        // Add new value to the heap
        minHeap.push(val);
        
        // If heap exceeds size k, remove the smallest element
        if (minHeap.size() > k_size) {
            minHeap.pop();
        }
        
        // The root of the min-heap is the kth largest element
        return minHeap.top();
    }
};
