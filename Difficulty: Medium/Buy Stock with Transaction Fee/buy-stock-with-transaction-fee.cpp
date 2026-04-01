class Solution {
  public:
    int maxProfit(vector<int>& arr, int k) {
        // Code here
        
        int n=arr.size(); 
        
        if(n==0){
            return 0;
        }  
        
        int cash=0;
        int hold=-arr[0];
        
        for(int i=0;i<n;i++){
            
            int prevCash=cash;
            
            
            // Sell Stock
            cash=max(cash,hold+arr[i]-k);
            
            // Buy Stock
            hold=max(hold,prevCash-arr[i]);
            
        }
        
        return cash;
    }
};