class Solution {
  public:
    int maxSubstring(string &s) {
        // code here
        
         int n = s.size();
        int one = 0;
        int zero = 0;
        
        int ans = -1;
        
        for(int i=0;i<n;i++){
            
            if(s[i]=='1')one++;
            else zero++;
            
            int diff = zero-one;

            if(diff<=0){ 
                one=0;
                zero=0;
            }
            else{
                
                ans = max(ans,diff);
                
            }
            
        }
        
        return ans;
    }
};