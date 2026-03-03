class Solution {
public: 


    string f(string s){

        for(int i=0;i<s.length();i++){

            if(s[i]=='0'){
                s[i]='1';
            }
            else{
                s[i]='0';
            }
        }

         reverse(s.begin(),s.end());

         return s;
    }
    char findKthBit(int n, int k) {

        vector<string>s(n); 
        s[0]="0";

        for(int i=1;i<n;i++){
            
          string revInv=f(s[i-1]);
            s[i]=s[i-1]+"1"+revInv;
        }

        return s[n-1][k-1];
        
    }
};