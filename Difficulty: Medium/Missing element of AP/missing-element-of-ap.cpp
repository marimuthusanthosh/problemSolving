//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
  
int findMissing(vector<int>& arr) {
    int diff = arr[1] - arr[0];
    int c = 0;

    for (int i = 2; i < arr.size(); i++) {
        c = arr[i] - arr[i - 1];
        if (c == diff) {
            diff = c;
        }
    }

    int ele = 0;
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i] + diff != arr[i + 1]) {
            return arr[i] + diff;
        }
    }

    return arr[arr.size() - 1] + diff;
 }

};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends