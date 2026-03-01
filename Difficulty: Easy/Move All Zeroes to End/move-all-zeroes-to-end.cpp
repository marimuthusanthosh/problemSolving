class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int j=0;
        
        for(int i=0;i<arr.size();i++)
        {
            
            if(arr[i] != 0)
            {  int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                j++;
            }
            
        }
        
    }
};