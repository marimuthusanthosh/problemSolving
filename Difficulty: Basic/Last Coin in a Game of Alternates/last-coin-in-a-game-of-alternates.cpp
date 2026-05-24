class Solution {
  public:
    int coin(vector<int>& arr) {
        // code here
        
        int mini = *min_element(arr.begin(), arr.end());
        
        return mini;
        
        
        
    }
};