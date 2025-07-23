class Solution {
    public int subarraySum(int[] arr) {
        // code 
         int n = arr.length;
        long totalSum = 0;
    
        for (int i = 0; i < n; i++) {
            long contribution = (long) arr[i] * (i + 1) * (n - i);
            totalSum += contribution;
        }
    
        return (int) totalSum;  // If you know the result won't overflow int
            
    }
}
