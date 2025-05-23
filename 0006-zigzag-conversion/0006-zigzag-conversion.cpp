class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        int n = s.length();

        if (numRows == 1 || numRows >= n) {
            return s;
        }

        vector<vector<char>> a(numRows, vector<char>(n, ' '));
        
        int i = 0, j = 0, l = 0;

        while (l < n) {
            for (i = 0; i < numRows && l < n; i++) {
                a[i][j] = s[l++];
            }

            for (i = numRows - 2, j = j + 1; i > 0 && l < n; i--, j++) {
                a[i][j] = s[l++];
            }
        }

        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < n; col++) {
                if (a[row][col] != ' ') {
                    ans += a[row][col];
                }
            }
        }

        return ans;
    }
};
