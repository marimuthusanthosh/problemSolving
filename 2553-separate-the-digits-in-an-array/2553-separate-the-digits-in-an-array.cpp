class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {

        int i=0,n=nums.size();
        vector<int>ans;

        while(i<n){
            
            stack<int>st;
            while(nums[i]!=0){
                st.push(nums[i]%10);
                nums[i]=nums[i]/10;
            }  

            while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
            }
            i++;
        }
        return ans;
    }
};