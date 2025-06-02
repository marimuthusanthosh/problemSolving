class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {   
        int n = heights.size();
        vector<int> leftarray(n, 0);
        vector<int> rightarray(n, 0);
        stack<int> st;   
        
        // Fill left array
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            leftarray[i] = (st.empty() ? -1 : st.top()); // Nearest smaller to left
            st.push(i);
        }

        // Clear the stack for the right array calculation
        while (!st.empty()) st.pop();

        // Fill right array
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            rightarray[i] = (st.empty() ? n : st.top()); // Nearest smaller to right
            st.push(i);
        }

        // Calculate the maximum area
        int maxi = 0;
        for (int i = 0; i < n; ++i) {
            maxi = max(maxi, (rightarray[i] - leftarray[i] - 1) * heights[i]); // Max area
        }

        return maxi; 
    }

    // Function to find the maximum size rectangle of 1's in the matrix
    int maximalRectangle(vector<vector<char>>& mat) {
        if (mat.empty()) return 0; // Handle edge case for empty matrix

        int maxArea = 0;
        int n = mat.size();
        int m = mat[0].size();
        vector<int> height(m, 0);
        // Traverse each row
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == '1') { // Compare with '1', as mat is a char matrix
                    height[j]++; // Increase height for consecutive 1's
                } else {
                    height[j] = 0; // Reset height for 0
                }
            }
            maxArea = max(maxArea, largestRectangleArea(height)); // Find max area for this row
        }
        return maxArea;
    }
};
