class Solution {
  public:
    // Direction vectors for moving right, left, up and down
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    
    // Check whether a cell lies inside the grid
    bool isValid(int row, int col, int n, int m)
    {
        return row >= 0 && col >= 0 && row < n && col < m;
    }
    
    // BFS to find towers reachable from a control station
    void bfs(vector<vector<int>> &strength, int n, int m, queue<pair<int, int>> &q,
             vector<vector<bool>> &reachable)
    {
    
        while (!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();
    
            // Visit all neighbouring towers
            for (int k = 0; k < 4; k++)
            {
                int newRow = row + dx[k];
                int newCol = col + dy[k];
    
                // Signal can propagate only to towers having
                // strength greater than or equal to the current tower
                if (isValid(newRow, newCol, n, m) && !reachable[newRow][newCol] &&
                    strength[newRow][newCol] >= strength[row][col])
                {
    
                    reachable[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
        }
    }
    int countCoordinates(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
    
        queue<pair<int, int>> stationP, stationQ;
    
        // Stores towers reachable from Station P and Station Q
        vector<vector<bool>> reachP(n, vector<bool>(m, false));
        vector<vector<bool>> reachQ(n, vector<bool>(m, false));
    
        // Towers adjacent to Station P (top boundary)
        // and Station Q (bottom boundary)
        for (int j = 0; j < m; j++)
        {
            stationP.push({0, j});
            reachP[0][j] = true;
    
            stationQ.push({n - 1, j});
            reachQ[n - 1][j] = true;
        }
    
        // Towers adjacent to Station P (left boundary)
        // and Station Q (right boundary)
        for (int i = 0; i < n; i++)
        {
            stationP.push({i, 0});
            reachP[i][0] = true;
    
            stationQ.push({i, m - 1});
            reachQ[i][m - 1] = true;
        }
    
        // Run BFS from both stations
        bfs(mat, n, m, stationP, reachP);
        bfs(mat, n, m, stationQ, reachQ);
    
        int count = 0;
    
        // Count towers reachable from both stations
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (reachP[i][j] && reachQ[i][j])
                {
                    count++;
                }
            }
        }
    
        return count;
    }
};