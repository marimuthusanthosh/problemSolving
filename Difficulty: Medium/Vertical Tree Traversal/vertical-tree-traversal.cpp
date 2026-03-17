class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        
        map<int, vector<int>> mp;   // FIXED
        queue<pair<Node*, int>> q;
        
        if(root == NULL) return {};
        
        q.push({root, 0});
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            Node* node = it.first;
            int index = it.second;
            
            // Store all nodes for this vertical line
            mp[index].push_back(node->data);
            
            if(node->left != NULL) {
                q.push({node->left, index - 1});
            }
            
            if(node->right != NULL) {
                q.push({node->right, index + 1});
            }
        }
        
        vector<vector<int>> ans;
        
        for(auto it : mp) {
            ans.push_back(it.second);  // vector<int>
        }
        
        return ans;
    }
};