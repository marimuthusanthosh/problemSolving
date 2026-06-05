class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }

    string lexicographicallySmallest(string &s, int k) {
        int n = s.size();

        // Correct k
        if (isPowerOfTwo(n))
            k /= 2;
        else
            k *= 2;

        // Impossible or empty result
        if (k >= n)
            return "-1";

        string res;

        for (char ch : s) {
            while (!res.empty() && k > 0 && res.back() > ch) {
                res.pop_back();
                k--;
            }
            res.push_back(ch);
        }

        // Remove remaining characters from the end
        while (k > 0 && !res.empty()) {
            res.pop_back();
            k--;
        }

        if (res.empty())
            return "-1";

        return res;
    }
};