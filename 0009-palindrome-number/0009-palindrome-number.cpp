class Solution {
public:
    bool isPalindrome(int x) 
    {  
        if(x<0){
            return false;
        }
        string a=to_string(x);
        int l=0,r=a.length()-1; 
        while(l<r){
            if(a[l]!=a[r]){
                return false;
            }
            l++; 
            r--;
        }
    return true;
    }
};