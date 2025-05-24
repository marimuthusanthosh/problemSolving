class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
        
        int n=s.length(),sum=0;
        for(int i=0;i<n;i++){
            
            for(int j=1;j<=n-i;j++){
                
                // cout<<stoi(s.substr(i,j))<<endl;
                
                sum=sum+stoi(s.substr(i,j));
            }
        }
        return sum;
    }
};