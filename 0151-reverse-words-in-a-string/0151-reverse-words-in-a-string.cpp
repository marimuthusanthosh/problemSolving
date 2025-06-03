class Solution {
public:
    string reverseWords(string s) 
    { 
        s=s+" ";
        int n=s.length();     
        stack<string>stack;
        string k="";
        for(int i=0;i<n;i++)
        {
            if(s[i]!=' ')
            {
            k=k+s[i]; 
            } 
            else
            {    
                if(k.length()!=0)  
                {
                  stack.push(k); 
                }
               k=""; 
            }
        }  

        k="";
        while(!stack.empty())
        { 

            k=k+stack.top();      
            k=k+" ";
            stack.pop();
        } 
    k.pop_back();

    return k;
    
    }
};