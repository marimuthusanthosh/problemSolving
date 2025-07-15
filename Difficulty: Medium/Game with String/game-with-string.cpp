class Solution {
  public:
  
   int minValue(string &s, int k) {
    unordered_map<char, int> mp;
    for (char ch : s) {
        mp[ch]++;
    }

    priority_queue<int> pq;
    for (auto it : mp) {
        pq.push(it.second);
    }

    while (k > 0 && !pq.empty()) {
        int top = pq.top();
        pq.pop();
        top--;
        if (top > 0) pq.push(top);
        k--;
    }

    int ans = 0;
    while (!pq.empty()) {
        int x = pq.top();
        pq.pop();
        ans += x * x;
    }

    return ans;
}
    
};