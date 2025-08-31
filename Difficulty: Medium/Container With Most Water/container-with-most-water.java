class Solution {
    public int maxWater(int a[]) {
        // Code Here
        
        int maxArea=0;
        int l=0, r=a.length-1; 
        
        while(l<r){
            
            
            if(a[l]<a[r]){
                
                maxArea=Math.max(a[l]*(r-l),maxArea);
                l++; 
            }
            else{
                maxArea=Math.max(a[r]*(r-l),maxArea);
                r--;
            }
        }
        
        return maxArea;
    }
}