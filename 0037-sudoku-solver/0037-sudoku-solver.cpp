class Solution {
public:
    bool check(int row, int col, vector<vector<char>>& board, char k) {
        for (int i = 0; i < 9; i++) 
        {
            if (board[row][i] == k || board[i][col] == k) 
            {
                return false;
            }
        }
        int startRow = row / 3 * 3;
        int startCol = col / 3 * 3;
        for (int i = startRow; i < startRow + 3; i++) 
        {
            for (int j = startCol; j < startCol + 3; j++) 
            {
                if (board[i][j] == k) 
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool solutions(vector<vector<char>>& board) 
    {
        for (int i = 0; i < 9; i++) 
        {
            for (int j = 0; j < 9; j++) 
            {
                if (board[i][j] == '.') 
                {
                    for (char k = '1'; k <= '9'; k++) 
                    {
                        if (check(i, j, board, k)) 
                        {
                            board[i][j] = k;
                            if (solutions(board)) 
                            {
                                return true;
                            } else 
                            {
                                board[i][j] = '.'; 
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) 
    {
        solutions(board);
    }
};