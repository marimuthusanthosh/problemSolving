class Solution {
  public:
    int findIndex(string &s) {
        // code here
        int r=0;
        int n=s.length();
        
        for(char c : s){
            
            if(c==')'){
                r++;
            }
            
        }
        if(r==0){
            return 0;
        }
         if(r == n)
         {
         return n;
             
         }
        int l=0;
        for(int i=0;i<n;i++){
            
            
            if(r==l){
                return i;
            }
            if(s[i]=='('){
                l++;
            }
            else{
                r--;
            }
            
        }
        
        return n;
    }
};