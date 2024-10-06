//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(int row, int col, int n, int m, vector<vector<char>> &grid, vector<vector<int>> &vis){
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int delrow = -1; delrow < 2; delrow++){
                for(int delcol = -1; delcol < 2; delcol++){
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                            && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    //cout<< i <<" " << j << '\n';
                    cnt++;
                    bfs(i, j, n, m, grid, vis);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends