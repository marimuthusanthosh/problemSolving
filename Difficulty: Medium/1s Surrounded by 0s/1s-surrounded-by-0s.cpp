class Solution {
public:

    // ─── BFS from boundary 1s → mark all escapable cells ─────
    void bfs(int i, int j, vector<vector<int>>& grid,
             vector<vector<int>>& vis,
             vector<int>& r1, vector<int>& r2) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        vis[i][j] = 1;                            // mark as escapable
        q.push({i, j});

        while (!q.empty()) {

            int first  = q.front().first;
            int second = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {

                int newFirst  = first  + r1[k];
                int newSecond = second + r2[k];

                if (newFirst  >= 0 && newFirst  < n &&
                    newSecond >= 0 && newSecond < m &&
                    grid[newFirst][newSecond] == 1 &&
                    !vis[newFirst][newSecond]) {

                    vis[newFirst][newSecond] = 1;  // mark escapable
                    q.push({newFirst, newSecond});
                }
            }
        }
    }

    int cntOnes(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> r1{0,  0, -1, 1};
        vector<int> r2{-1, 1,  0, 0};

        // ── Step 1: BFS from all boundary 1s ──────────────────
        // First and last row
        for (int j = 0; j < m; j++) {
            if (grid[0][j]   == 1 && !vis[0][j])
                bfs(0, j, grid, vis, r1, r2);     // top row
            if (grid[n-1][j] == 1 && !vis[n-1][j])
                bfs(n-1, j, grid, vis, r1, r2);   // bottom row
        }

        // First and last column
        for (int i = 0; i < n; i++) {
            if (grid[i][0]   == 1 && !vis[i][0])
                bfs(i, 0, grid, vis, r1, r2);     // left col
            if (grid[i][m-1] == 1 && !vis[i][m-1])
                bfs(i, m-1, grid, vis, r1, r2);   // right col
        }

        // ── Step 2: Count unvisited 1s = trapped cells ────────
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    count++;                       // not escapable = trapped
                }
            }
        }
        return count;
    }
};