class Solution {
    public int findFinalValue(int[] nums, int original) {

      
            Set<Integer>s=new HashSet<Integer>(); 

            for(int num:nums){
                s.add(num);
            }

            while(s.contains(original)){
                original=2*original;
            }

            return original;
        
    }
}