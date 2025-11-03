class Solution {
    public int smallestNumber(int n) {

        int a=1,ans=0;
        if(n==1){
            return 1;
        }

       while(ans<n){

        ans=ans+a;
        System.out.println(a);
        a=a<<1;
       }
        return ans; 
        
    }
}