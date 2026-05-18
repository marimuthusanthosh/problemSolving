class Solution {
public:

    int f(int n) {

        if (n == 0) {
            return 0;
        }

        int a = f(n / 2);

        int b = f(n / 3);

        int c = f(n / 4);

        return max(n, a + b + c);
    }

    int maxSum(int n) {

        return f(n);
    }
};