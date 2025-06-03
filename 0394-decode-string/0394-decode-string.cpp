class Solution {
public:
    string decodeString(string s)
     { 
         stack<int>a;
         stack<string>b;  
         int sum=0;
         string ans=""; 
         int i,j;
        for(i=0;i<s.length();i++)
        {
            if(isdigit(s[i]))
            {  
                sum=sum*10+(int)(s[i]-'0');
            }
            else if(isalpha(s[i]))
            {
                ans=ans+s[i];     
            } 
            else if(s[i]=='[')
            {
                b.push(ans);   
                a.push(sum);   
                 ans="";   
                 sum=0; 
            }   
            else if(s[i]==']')
            {   
                string  res=b.top();  
                for(int k=0;k<a.top();k++)
                {
                    res=res+ans;
                } 
                a.pop();   
                b.pop();   
                ans=res;
            }
        } 
        return ans;
    }
};