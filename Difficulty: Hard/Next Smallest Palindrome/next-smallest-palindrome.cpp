class Solution {
public:
    vector<int> nextPalindrome(vector<int>& num) {
        
        int n = num.size();
        vector<int> ans = num;

        // 1️⃣ make palindrome
        for (int i = 0; i < n/2; i++) {
            ans[n-1-i] = ans[i];
        }

        // 2️⃣ if already greater
        if (ans > num) return ans;

        // 3️⃣ add 1 to middle
        int carry = 1;
        int i = (n-1)/2;

        while (i >= 0 && carry) {
            ans[i] += carry;
            carry = ans[i] / 10;
            ans[i] %= 10;
            i--;
        }

        // edge case: 999 → 1001
        if (carry) {
            vector<int> res(n+1, 0);
            res[0] = res[n] = 1;
            return res;
        }

        // 4️⃣ mirror again
        for (int i = 0; i < n/2; i++) {
            ans[n-1-i] = ans[i];
        }

        return ans;
    }
};