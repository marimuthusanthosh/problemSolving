class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        vector<pair<int,int>> a; 
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if (matrix[i][j] == 0) {
                    a.push_back(make_pair(i, j));
                }
            }
        }   
        
        for(int k = 0; k < a.size(); k++)
        {
            int row = a[k].first;
            int col = a[k].second;
            
            for(int i = 0; i < matrix[0].size(); i++)
            {
                matrix[row][i] = 0;
            }    
            for(int j = 0; j < matrix.size(); j++)
            {
                matrix[j][col] = 0;
            }  
        }          
    }
};