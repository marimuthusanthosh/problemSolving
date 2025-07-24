class Solution {
    public int missingNumber(int[] arr) {
        // code here
        
          PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        for (int num : arr) {
            if (num > 0) {
                minHeap.add(num);
            }
        }

        int smallest = 1;

        while (!minHeap.isEmpty()) {
            
            int current = minHeap.poll();

            if (current == smallest) {
                smallest++;
            } else if (current > smallest) {
                return smallest;
            }
            // If current < smallest, just ignore duplicates
        }

        return smallest;

    }
}
