class Solution {
public:
    int lengthOfLastWord(string s)
    {
           int n=s.length();  
          int c=0,k=0,i;
          for(i=n-1;i>=0;i--)
          { 
                if(s[i]!=' ')
                {
                    c++;
                } 
                else
                {
                    if(c!=0)
                    {
                    break;
                    }
                    // c=0;
                }
          }   

    return c;
    }
};