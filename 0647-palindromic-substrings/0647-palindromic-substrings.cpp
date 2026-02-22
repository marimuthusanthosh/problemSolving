class Solution { 
public: 
   
   int f(string s,int left,int right){ 
    int c=0;
    while(left>=0&&right<s.length()&&s[left]==s[right]){
        c++; 
        left--; 
        right++;
    } 
    return c;
   }
    int countSubstrings(string s) {


        int count=0;
        for(int i=0;i<s.length();i++){

            count=count+f(s,i,i);

            count=count+f(s,i,i+1);
        }

        return count;
        
        
    }
};