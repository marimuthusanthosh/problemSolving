class Solution {
    public boolean kLengthApart(int[] nums, int k) {

        int l=0,r=0,i=0,c1=0,c2=0; 
        int n=nums.length; 

        while(r<n){

            if(nums[r]==1&&c1==0){
                c1=1;
                l=r; 
            }
            else if(nums[r]==1&&c2==0){
                c2=1;
                if(c1==1&&c2==1){

                    if(r-l-1<k){
                        return false;
                    }
                }
                    l=r;
                    c2=0;
            }
            r++;
        } 
        return true;       
    }
}