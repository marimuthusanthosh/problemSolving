class Solution {

    // Recursive helper function
    void f(int i, int j, int m, int n, int ans[][], int f1[], int f2[]) {

        // Boundary and visited check
        if (i < 0 || i >= m || j < 0 || j >= n || ans[i][j] != 0) {
            return;
        }

        // Mark current cell as guarded
        ans[i][j] = 1;

        // Move in 4 directions
        for (int k = 0; k < 4; k++) {
            f(i + f1[k], j + f2[k], m, n, ans, f1, f2);
        }
    }

    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {

        int ans[][] = new int[m][n];

        // Mark guards as 2
        for (int i = 0; i < guards.length; i++) {
            ans[guards[i][0]][guards[i][1]] = 2;
        }

        // Mark walls as 1
        for (int i = 0; i < walls.length; i++) {
            ans[walls[i][0]][walls[i][1]] = 1;
        }

        // Directions: up, down, left, right
        int f1[] = {1, -1, 0, 0};
        int f2[] = {0, 0, 1, -1};

        // For each guard, mark visible cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (ans[i][j] == 2) {
                    for (int k = 0; k < 4; k++) {
                        int x = i + f1[k];
                        int y = j + f2[k];

                        while (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] != 1 && ans[x][y] != 2) {
                            if (ans[x][y] == 0)
                                ans[x][y] = 3; // mark guarded
                            x += f1[k];
                            y += f2[k];
                        }
                    }
                }
            }
        }

        // Count unguarded cells
        int c = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (ans[i][j] == 0) {
                    c++;
                }
            }
        }

        return c;
    }
}
