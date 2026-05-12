class Solution {
public:

    int findPosition(int n) {

        // no set bit
        if (n == 0) {
            return -1;
        }

        // more than one set bit
        if ((n & (n - 1)) != 0) {
            return -1;
        }

        int c = 1;

        // find position
        while ((n & 1) == 0) {

            n = n >> 1;
            c++;
        }

        return c;
    }
};