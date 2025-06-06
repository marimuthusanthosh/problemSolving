class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;  
        for(int i : nums){
            pq.push(i);
        }  
        int c=0;
        while(c<k-1){
            pq.pop();
            c++;
        }
        return pq.top();       
    }
};