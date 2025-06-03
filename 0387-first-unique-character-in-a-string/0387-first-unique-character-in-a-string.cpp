class Solution {
public:
    int firstUniqChar(string s)
     {
         for(int i=0;i<s.length();i++)
         { 
             int f=0;
             for(int j=0;j<s.length();j++)
             {
                 if(s[i]==s[j]&&i!=j)
                 { 
                     f=1;
                     break;
                 }
             }  
             if(f==0)
             {
                 return i;
             }
         } 
         return -1;
    }
};