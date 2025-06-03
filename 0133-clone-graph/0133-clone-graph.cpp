class Solution {
public:
    Node* cloneGraph(Node* node) { 

        if(node==nullptr){
            return nullptr;
        }
       unordered_map<Node*, Node*> mp; 
       mp[node]= new Node(node->val);  
       queue<Node*>q;
       q.push(node);
       while(!q.empty()){
        Node* current=q.front(); 
        q.pop();
        for(Node* neigh :current->neighbors){  
            if(mp.find(neigh)==mp.end()){  
                mp[neigh]=new Node(neigh->val);
                q.push(neigh);
            }
             mp[current]->neighbors.push_back(mp[neigh]);
        }
       }
      return mp[node];
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/