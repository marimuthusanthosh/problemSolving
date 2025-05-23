class Solution {
public:
    int strStr(string haystack, string needle)
    {
           int n=haystack.length();   
           int m=needle.length(); 
            int i=0;
            
            while(i<n-m+1)
            {
                if(haystack.substr(i,m)==needle)
                 return i; 
                i++;
            }
            return -1;
           
    }
};