class Solution {
public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        
        int n = arr.size();
        
        int l = 0;
        int xorAns = 0;
        int maxi = 0;
        
        for(int r = 0; r < n; r++){
            
            xorAns ^= arr[r];   
            
            if(r - l + 1 == k){
                
                maxi = max(maxi, xorAns);
                
                xorAns ^= arr[l]; 
                l++;
            }
        }
        
        return maxi;
    }
};