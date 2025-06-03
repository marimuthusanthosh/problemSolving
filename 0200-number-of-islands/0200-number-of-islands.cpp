class Solution {
public:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){

        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int N=grid.size();
        int M=grid[0].size();

        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int delrow=-1;delrow<=1;delrow++)
            {
                for(int delcol=-1;delcol<=1;delcol++)
                {
                    int neighrow=row+delrow;
                    int neighcol=col+delcol;

                    if((abs(delrow-delcol)==1) && (neighrow>=0 && neighrow<N && neighcol>=0 && neighcol<M && grid[neighrow][neighcol]=='1' && !vis[neighrow][neighcol]))
                    {
                        vis[neighrow][neighcol]=1;
                        q.push({neighrow,neighcol});
                    }
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {   
           
        int N=grid.size();
        int M=grid[0].size();
        vector<vector<int>> vis(N, vector<int>(M,0));
        int count=0;
        for(int row=0;row<N;row++)
        {
            for(int col=0;col<M;col++)
            {
                if(!vis[row][col] && grid[row][col]=='1')
                {
                    bfs(row, col, vis, grid);
                    count++;
                }
            }
        }
        return count;
    }
};