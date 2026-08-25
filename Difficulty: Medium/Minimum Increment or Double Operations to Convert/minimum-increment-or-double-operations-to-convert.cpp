class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        // code here
        int n = arr.size();

        int ans = 0;
        int half = 0;

        for(int i=0; i<n; i++) {       

            int temp = 0;

            while(arr[i] > 0) {     
                if(arr[i] % 2 == 0) {
                    arr[i] = arr[i]>>1;

                    temp++;
                } 
                else {
                    ans++;
                    arr[i]--;
                }
            }

            half = max(half,temp);   
        }

        return ans + half; 
    }
};