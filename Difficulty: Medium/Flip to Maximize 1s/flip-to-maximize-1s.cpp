class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        
        int n = arr.size();
        
        int c = 0;      // current sum (Kadane)
        int s = 0;      // max sum
        int n1 = 0;     // count of 1s
        
        for(int i = 0; i < n; i++){
            
            if(arr[i] == 0){
                c += 1;
            }
            else{
                c -= 1;
                n1++;
            }
            
            if(c < 0)
                c = 0;
            
            s = max(s, c);
        }
        
        return n1 + s;
    }
};