class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        int dir = 0; // 0=E,1=S,2=W,3=N

        int r = 0;
        int c = 0;

        while(r >= 0 && r < n && c >= 0 && c < m){

            dir = (dir + mat[r][c]) % 4;

            if(mat[r][c] == 1){
                mat[r][c] = 0;
            }

            if(dir == 0){
                c++;
            }
            else if(dir == 1){
                r++;
            }
            else if(dir == 2){
                c--;
            }
            else{
                r--;
            }
        }

        if(r < 0) r++;
        else if(r >= n) r--;
        else if(c < 0) c++;
        else if(c >= m) c--;

        return {r, c};
    }
};