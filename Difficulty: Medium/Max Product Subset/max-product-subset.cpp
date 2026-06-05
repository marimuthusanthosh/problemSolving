class Solution {
  public:
    int modulo = 1000000007;

    int findMaxProduct(vector<int>& arr) {
        // code here
        int n = arr.size();
        if (n ==1) return arr[0];
        int nonzero = 0;
        long ans = 1;
        int maxNeg = INT_MIN;
        for(int i=0; i<n; i++){
            if(arr[i] != 0){
                ans *= arr[i];
                ans %= modulo;
                nonzero++;
                if(arr[i] < 0){
                    maxNeg = max(maxNeg, arr[i]);
                }
            }
        }
        if(nonzero == 0) return 0;
        if(ans > 0) return ans;
        if(nonzero == 1) return 0;
        return ans/maxNeg;
        
    }
};