class Solution {
public:

    vector<int> makeBeautiful(vector<int> a) {

        vector<int> ans;

        int n = a.size();

        int i = 0;

        while (i < n) {

            if (!ans.empty() &&

               ((ans.back() < 0 && a[i] >= 0) ||
                (ans.back() >= 0 && a[i] < 0))) {

                ans.pop_back();
            }
            else {

                ans.push_back(a[i]);
            }

            i++;
        }

        return ans;
    }
};