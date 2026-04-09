class Solution {
public:
    vector<int> find3Numbers(vector<int> &a) {
        
        int n = a.size();
        
        vector<int> leftMin(n), rightMax(n);

        // fill leftMin
        leftMin[0] = a[0];
        for (int i = 1; i < n; i++) {
            leftMin[i] = min(leftMin[i-1], a[i]);
        }

        // fill rightMax
        rightMax[n-1] = a[n-1];
        for (int i = n-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], a[i]);
        }

        // find valid triplet
        for (int j = 1; j < n-1; j++) {
            if (leftMin[j-1] < a[j] && a[j] < rightMax[j+1]) {
                return {leftMin[j-1], a[j], rightMax[j+1]};
            }
        }

        return {};
    }
};