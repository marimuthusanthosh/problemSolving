class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        // code here
        string s="";
        
        while(n!=0){
            
            s=s+to_string(n%2);
            n=n/2;
        }
        int l=0, r=s.size()-1;
        
        while(l<r){
            
            if(s[l]!=s[r]){
                return false;
            }
            l++; 
            r--;
        }
        return true;
    }
};