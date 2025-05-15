//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countSubstring(string &s) {
        
        
        map<char, int> mp;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
    
        int count = 0;
        for (auto it : mp) {
            
            int f = it.second;
            count += f * (f - 1) / 2 + f;
            
        }
    
        return count;
            
        }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.countSubstring(str) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends