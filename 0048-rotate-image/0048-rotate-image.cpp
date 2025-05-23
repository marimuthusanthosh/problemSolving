// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix)
//     {   
//         vector<vector<int>>a;  
//         int n=matrix.size();  
//         a=matrix;
//         for(int i=0;i<matrix.size();i++)
//         {
//             for(int j=0;j<matrix[i].size();j++)
//             {
//                 a[j][n-1-i]=matrix[i][j];
//             }
//         }
//         matrix=a;
//     }
// };
// optimized code
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose the matrix
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
