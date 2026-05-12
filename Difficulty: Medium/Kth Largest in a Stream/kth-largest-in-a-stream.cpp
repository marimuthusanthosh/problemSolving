class Solution {
public:

    vector<int> kthLargest(vector<int>& arr, int k) {

        priority_queue<int, vector<int>, greater<int>> pq;

        vector<int> ans;

        int i = 0;
        int n = arr.size();

        while (i < n) {

            pq.push(arr[i]);

            // keep only k largest elements
            if (pq.size() > k) {
                pq.pop();
            }

            if (pq.size() < k) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(pq.top());
            }

            i++;
        }

        return ans;
    }
};