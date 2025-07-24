class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Insert only positive values into the minHeap
        for (int num : arr) {
            if (num > 0) minHeap.push(num);
        }

        int smallest = 1;

        while (!minHeap.empty()) {
            int current = minHeap.top();
            minHeap.pop();

            // Skip duplicates
            if (current == smallest) {
                smallest++;
            } else if (current > smallest) {
                // Found the missing number
                return smallest;
            }
            // If current < smallest, continue (due to duplicates)
        }

        // If all elements are consecutive starting from 1
        return smallest;
    }
};

