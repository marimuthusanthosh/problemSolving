class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        // 0-based prefix sum
        vector<vector<int>> prefix(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                prefix[i][j] = mat[i][j];
                
                if(i > 0)
                    prefix[i][j] += prefix[i-1][j];
                
                if(j > 0)
                    prefix[i][j] += prefix[i][j-1];
                
                if(i > 0 && j > 0)
                    prefix[i][j] -= prefix[i-1][j-1];
            }
        }
        
        int res = 0;
        
        // treat (i,j) as bottom-right corner
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                for(int len = 1; len <= min(i+1, j+1); len++){
                    
                    int r1 = i - len + 1;
                    int c1 = j - len + 1;
                    
                    int sum = prefix[i][j];
                    
                    if(r1 > 0)
                        sum -= prefix[r1-1][j];
                    
                    if(c1 > 0)
                        sum -= prefix[i][c1-1];
                    
                    if(r1 > 0 && c1 > 0)
                        sum += prefix[r1-1][c1-1];
                    
                    if(sum == x)
                        res++;
                }
            }
        }
        
        return res;
    }
};