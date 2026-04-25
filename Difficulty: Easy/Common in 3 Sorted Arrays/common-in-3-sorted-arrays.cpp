class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        
        map<int,int> mp;
        vector<int> ans;
        
        set<int> s1(a.begin(), a.end());
        set<int> s2(b.begin(), b.end());
        set<int> s3(c.begin(), c.end());
        
        for(int x : s1) mp[x]++;
        for(int x : s2) mp[x]++;
        for(int x : s3) mp[x]++;
        
        for(auto it : mp){
            if(it.second == 3)
                ans.push_back(it.first);
        }
        
        return ans;
    }
};