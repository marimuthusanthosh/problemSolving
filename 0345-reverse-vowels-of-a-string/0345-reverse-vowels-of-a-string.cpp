class Solution {
public:  
    bool isvowel(char a)
    {
            if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u' || a=='A'||a=='E'||a=='I'||a=='O'||a=='U')
            {
               return true;
            }  
            return false;
    }
    string reverseVowels(string s) 
    {     
     
        int n=s.length();
       int l=0,r=n-1;  
        while(l<r)
        {  
           if(isvowel(s[l]) && isvowel(s[r]))
           {
            swap(s[l], s[r]);
            l++;
            r--;
           }
           if(!isvowel(s[l]))
            {
                l++;
            }
            if(!isvowel(s[r]))
            {
                r--;
            }
        }

    return s;
    }
};