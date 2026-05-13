class Solution {
public:

    long long sumXOR(vector<int> &arr) {

        long long sum = 0;

        int n = arr.size();

        // check every bit
        for (int i = 0; i < 32; i++) {

            long long setBit = 0;

            for (int j = 0; j < n; j++) {

                if ((arr[j] & (1 << i)) != 0) {
                    setBit++;
                }
            }

            long long unsetBit = n - setBit;

            sum = sum +
                  (setBit * unsetBit * (1LL << i));
        }

        return sum;
    }
};