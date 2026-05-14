class Solution {
public:

    // ─── STEP 1: Build LPS (Longest Proper Prefix which is Suffix) ───
    // LPS table tells us how many characters we can skip on mismatch
    vector<int> buildLPS(vector<int>& b) {
        int m = b.size();
        vector<int> lps(m, 0);

        int len = 0;                          // length of previous longest prefix suffix
        int i = 1;

        while (i < m) {
            if (b[i] == b[len]) {
                len++;
                lps[i] = len;                 // match found, extend prefix
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];       // fall back using lps (don't increment i)
                } else {
                    lps[i] = 0;               // no prefix suffix match
                    i++;
                }
            }
        }
        return lps;
    }

    // ─── STEP 2: KMP Search ──────────────────────────────────────────
    vector<int> search(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        vector<int> ans;

        if (m == 0 || m > n) return ans;      // edge cases

        // Build LPS table for pattern b[]
        vector<int> lps = buildLPS(b);

        int i = 0;                            // pointer for a[]
        int j = 0;                            // pointer for b[]

        while (i < n) {
            if (a[i] == b[j]) {
                i++;
                j++;                          // characters match, move both
            }

            if (j == m) {
                // Full match found at index i-j
                ans.push_back(i - j);
                j = lps[j - 1];              // look for next match using lps
            } else if (i < n && a[i] != b[j]) {
                if (j != 0) {
                    j = lps[j - 1];          // mismatch: fall back using lps
                } else {
                    i++;                     // no fallback possible, move i
                }
            }
        }
        return ans;
    }
};