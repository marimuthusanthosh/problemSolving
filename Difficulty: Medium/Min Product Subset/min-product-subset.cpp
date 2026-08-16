class Solution {
public:
    int minProd(vector<int>& arr) {

        int n = arr.size();

        int prod = 1;
        int maxiNeg = INT_MIN;
        int miniPos = INT_MAX;
        bool neg = false;

        for (int i = 0; i < n; i++) {

            if (arr[i] != 0) {
                prod *= arr[i];
            }

            if (arr[i] < 0) {

                neg = true;
                maxiNeg = max(maxiNeg, arr[i]);
            }

            else {

                miniPos = min(miniPos, arr[i]);
            }
        }

        if (prod < 0) {
            return prod;
        }

        if (neg) {
            return prod / maxiNeg;
        }

        return miniPos;
    }
};