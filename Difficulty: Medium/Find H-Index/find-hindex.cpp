class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
    int n = citations.size();
        
        // Sort in descending order
        sort(citations.begin(), citations.end(), greater<int>());
        
        int h = 0;
        for (int i = 0; i < n; i++) {
            if (citations[i] >= i + 1) {
                h = i + 1;  // at least i+1 papers with >= i+1 citations
            } else {
                break;
            }
        }
        return h;


    }
};