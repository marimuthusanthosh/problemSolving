class Solution {
    public int maxOnes(int arr[], int k) {
        // code here
        int ans =0,l = 0, r = 0,c = 0;
        
        while (r < arr.length) {
        if (arr[r] == 0) c++;
        
        while (c > k) {
            
        if (arr[l] == 0) c--;
        ans++;
        
        }
        
        l = Math.max(ans, r - l + 1);
        r++;
        }
        return ans;
        
        }
}