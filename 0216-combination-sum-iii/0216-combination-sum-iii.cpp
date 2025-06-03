class Solution {
public:
    void f(int i, int sum, vector<int>& st, vector<vector<int>>& finalset, int k, int n) {
        if (st.size() == k) {
            if (sum == n) {
                finalset.push_back(st);
            }
            return;
        }
        
        if (i > 9) return;  // Constraint: numbers are from 1 to 9

        // Pick `i`
        st.push_back(i);
        f(i + 1, sum + i, st, finalset, k, n);
        st.pop_back();  // Backtrack
        
        // Don't pick `i`
        f(i + 1, sum, st, finalset, k, n);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> st;
        vector<vector<int>> finalset;
        f(1, 0, st, finalset, k, n);
        return finalset;
    }
};


// Memorization

