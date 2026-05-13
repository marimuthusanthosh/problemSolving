class Solution {
public:

    int countSetBits(int n) {

        int sum = 0;

        while (n != 0) {

            if ((n & 1) == 1) {
                sum++;
            }

            n = n >> 1;
        }

        return sum;
    }

    vector<int> sortBySetBitCount(vector<int>& arr) {

        stable_sort(arr.begin(), arr.end(),
        [&](int a, int b) {

            return countSetBits(a) >
                   countSetBits(b);
        });

        return arr;
    }
};