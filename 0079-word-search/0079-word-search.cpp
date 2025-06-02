class Solution {
public:
    bool f(int x, int y, int k, vector<vector<char>>& board, string& word, int n, int m, vector<pair<int, int>>& p) {
        
        if (k == word.size()) {
            return true; 
        }
        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != word[k]) {
            return false;  
        }
        char temp = board[x][y];  
        board[x][y] = '#';        
        for (int i = 0; i < 4; i++) {
            int X = x + p[i].first;
            int Y = y + p[i].second;
            
            if (f(X, Y, k + 1, board, word, n, m, p)) {
                return true;  
            }
        }
        board[x][y] = temp;  
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<pair<int, int>> p = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};  // Directions: left, right, up, down
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {  // Start from matching first character
                    if (f(i, j, 0, board, word, n, m, p)) {
                        return true;
                    }
                }
            }
        }
        return false;  // Word not found
    }
};