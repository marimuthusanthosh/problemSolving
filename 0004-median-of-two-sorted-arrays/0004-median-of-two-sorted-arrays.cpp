class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
     {
        int n=nums1.size(),m=nums2.size(),i=0,j=0;
        vector<int>ans;
        while(i<n&&j<m){
            if(nums1[i]<nums2[j]){
              ans.push_back(nums1[i]);
              i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n){
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            ans.push_back(nums2[j]);
            j++;
        }

        int k=ans.size();
        if(k%2==0)
        {
            return (float)(ans[k/2]+ans[(k/2)-1])/2;
        } 
        else 
        {
            return (float)( ans[k/2]);
        }
    }
};