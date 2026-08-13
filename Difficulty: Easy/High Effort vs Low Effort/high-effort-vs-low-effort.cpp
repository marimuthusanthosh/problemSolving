class Solution {
public:
    int maxTask(vector<int>& h, vector<int>& l) {

        int n = h.size();

        int ans = max(h[0], l[0]); // best till previous day
        int prevAns = 0;           // best till i-2 day

        for (int i = 1; i < n; i++) {

            int takeLow = ans + l[i];
            int takeHigh = prevAns + h[i];

            int currAns = max(takeLow, takeHigh);

            prevAns = ans;
            ans = currAns;
        }

        return ans;
    }
};