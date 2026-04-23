class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        
        int sum = 0;
        int n = arr.size();
        
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
        
        // if sum is odd → impossible
        if(sum % 2 != 0)
            return false;
        
        int sum1 = 0;
        
        for(int i = 0; i < n; i++){
            sum1 += arr[i];
            
            if(sum1 == sum / 2){
                return true;
            }
        }
        
        return false;
    }
};