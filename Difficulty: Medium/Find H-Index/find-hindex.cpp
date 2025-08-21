class Solution {
  public:
    int hIndex(vector<int>& citations) {
 priority_queue<pair<int,int>> maxHeap;
        map<int,int> mp;  // key = citation, value = frequency
        
        int n = citations.size();
        
        // count frequency of each citation
        for(int i=0; i<n; i++){
            mp[citations[i]]++;
        }
        
        // push into maxHeap (citation, frequency)
        for(auto &it : mp){
            maxHeap.push({it.first, it.second});
        }
        
        int h = 0, papers = 0;
        
        // process from largest citation downward
        while(!maxHeap.empty()){
            auto [c, f] = maxHeap.top();
            maxHeap.pop();
            
            papers += f;  // total papers with at least 'c' citations
            h = max(h, min(c, papers));
        }
        
        return h;
    }
};