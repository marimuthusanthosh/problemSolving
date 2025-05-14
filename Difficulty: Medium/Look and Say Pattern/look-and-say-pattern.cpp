//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string f(int n) {
        if (n == 1) {
            return "1";
        }
        
        string prev = f(n - 1);
        return say(prev);
    }
    
    string say(string str) {
        string res = "";
        int i = 0;
        
        while (i < str.size()) {
            int count = 1;
            while (i + 1 < str.size() && str[i] == str[i + 1]) {
                count++;
                i++;
            }
            res += to_string(count) + str[i];
            i++;
        }
        
        return res;
    }
    
    string countAndSay(int n){
        
        return f(n);
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends