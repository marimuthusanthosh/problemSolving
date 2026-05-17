class Solution {
public:

    int findSmallest(vector<int> &arr) {

        sort(arr.begin(), arr.end());

        int mini = 1;

        int i = 0;

        while (i < arr.size()) {

            if (arr[i] > mini) {

                return mini;
            }

            mini = mini + arr[i];

            i++;
        }

        return mini;
    }
};