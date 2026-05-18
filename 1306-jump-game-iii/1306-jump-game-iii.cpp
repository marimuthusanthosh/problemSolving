class Solution {
public:

    bool f(int i,
           vector<int>& a,
           vector<int>& vis) {

        if (i < 0 || i >= a.size()) {
            return false;
        }

        if (a[i] == 0) {
            return true;
        }

        if (vis[i] == 1) {
            return false;
        }

        vis[i] = 1;

        return f(i + a[i], a, vis) ||
               f(i - a[i], a, vis);
    }

    bool canReach(vector<int>& arr,
                  int start) {

        vector<int> vis(arr.size(), 0);

        return f(start, arr, vis);
    }
};