class Solution {
public:
    void moveZeroes(vector<int>& nums)
     {        
         int n=nums.size(); 
         int c=0;
          for(int i=0;i<n;i++)
          {
              if(nums[i]==0)
              {    
                //  nums.push_back(0);  
                c++;
                //  nums.erase(nums.begin()+i);
              }      
              else
              {
               nums.push_back(nums[i]);
              }
          }
          for(int i=0;i<c;i++)
          {
            nums.push_back(0);
          }  
        nums.erase(nums.begin(),nums.begin()+n);
  }     
};


// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int left = 0;

//         for (int right = 0; right < nums.size(); right++) {
//             if (nums[right] != 0) {
//                 swap(nums[right], nums[left]);
//                 left++;
//             }
//         }        
//     }
// };