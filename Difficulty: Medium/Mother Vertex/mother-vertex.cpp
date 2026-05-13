class Solution {
public:

    // ─── DFS to track finish order ─────────────────────────────
    void dfs1(int node, vector<vector<int>>& adj,
              vector<bool>& visited, stack<int>& st) {

        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs1(neighbor, adj, visited, st);
            }
        }
        st.push(node);                        // push after all neighbors done
    }

    // ─── DFS to count reachable nodes ──────────────────────────
    void dfs2(int node, vector<vector<int>>& adj,
              vector<bool>& visited, int& count) {

        visited[node] = true;
        count++;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs2(neighbor, adj, visited, count);
            }
        }
    }

    // ─── MAIN ──────────────────────────────────────────────────
    int findMotherVertex(int V, vector<vector<int>>& edges) {

        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        // Step 2: DFS on all nodes → get finish order
        vector<bool> visited(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs1(i, adj, visited, st);
            }
        }

        // Step 3: Last finished node is the candidate
        int candidate = st.top();

        // Step 4: Verify candidate can reach ALL vertices
        fill(visited.begin(), visited.end(), false);
        int count = 0;
        dfs2(candidate, adj, visited, count);

        if (count != V) return -1;            // can't reach all → no mother vertex

        // Step 5: Find smallest mother vertex
        // Check all vertices smaller than candidate
        int result = candidate;
        for (int i = 0; i < candidate; i++) {
            fill(visited.begin(), visited.end(), false);
            count = 0;
            dfs2(i, adj, visited, count);
            if (count == V) {
                result = i;                   // found smaller mother vertex
                break;
            }
        }

        return result;
    }
};