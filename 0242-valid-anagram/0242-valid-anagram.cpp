class Solution {
public:
     bool isAnagram(string s, string t)
    {
          int n=s.length();    
          int l=t.length();   
          int i,j;
            if(n!=l)
            {
               return 0;
            }      
            else
            {     
               sort(s.begin(),s.end());
               sort(t.begin(),t.end());  
               if(s==t)
               {
                   return 1; 
               }
            }  
            return 0;
    }
};