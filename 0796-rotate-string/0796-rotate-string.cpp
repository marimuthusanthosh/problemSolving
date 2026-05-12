class Solution {
public:
    bool rotateString(string s, string goal) {

         int n=s.length();
         int r=n;
        for(int i=0;i<n;i++){

           string ans=s.substr(r,n-r)+s.substr(0,r);
            r--;
            if(ans==goal){
                return true;
            }

        }
        return  false;
    }
};