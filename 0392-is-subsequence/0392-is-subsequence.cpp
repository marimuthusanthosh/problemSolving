class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int n=s.length();
        int m=t.length();   
        int i=0,j;  
 
            for(j=0;j<m;j++)
            {
                if(s[i]==t[j])
                {
                  i++;
                }   
            }
    
        if(i==n)
        {
            return 1;
        } 
        return 0;

    }
};