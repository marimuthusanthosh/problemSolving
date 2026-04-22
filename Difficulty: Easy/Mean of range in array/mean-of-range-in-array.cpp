class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        
        int n = arr.size();
        int m = queries.size();
        
        vector<int> a(n), c(m);
        
        // prefix sum
        a[0] = arr[0];
        for(int i = 1; i < n; i++){
            a[i] = a[i-1] + arr[i];
        }
        
        // process queries
        for(int i = 0; i < m; i++){
            
            int l = queries[i][0];
            int r = queries[i][1];
            
            int sum;
            if(l == 0)
                sum = a[r];
            else
                sum = a[r] - a[l-1];
            
            int len = r - l + 1;
            
            c[i] = sum / len;   // floor automatically
        }
        
        return c;
    }
};