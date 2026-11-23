class Solution {
public:
    bool checkString(string s) {
        
        int a1=INT_MIN;
        int b1=INT_MIN;
        bool b=false;
        for(int i=0;i<s.length();i++){

            if(!b&&s[i]=='b'){
                b1=i;
                b=true;
            }
            if(s[i]=='a'){
                a1=i;
            }
        }

        if(b1>a1 ||b1==INT_MIN||a1==INT_MIN){
            return true;
        }
        return false;
    }
};