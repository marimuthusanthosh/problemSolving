class Solution {
public:
    char findTheDifference(string s, string t) {
        
       string k=s+t; 
       char a=0;
       int n=k.length(); 
       for(int i=0;i<n;i++){
           a=a^k[i];
       }    

       return a;
    }
};