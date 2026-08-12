class Solution {
  public:
    int MOD = 1e9 + 7;
    int dp[101][101];
    int solve1(int i, int j, vector <vector<int>> &mat) {
        int n = mat.size();
        if (i == n - 1 and j == n - 1) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if (i < n - 1 and mat[i][j] != 1) {
            ans = (ans + solve1(i + 1, j, mat)) % MOD;
        }
        if (j < n - 1 and mat[i][j] != 2) {
            ans = (ans + solve1(i, j + 1, mat)) % MOD;
        }
        dp[i][j] = ans;
        return ans;
    }
    int solve2(int i, int j, vector <vector<int>> &mat) {
        int n = mat.size();
        if (i == n - 1 and j == n - 1) {
            return mat[i][j];
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = -1e8;
        if (i < n - 1 and mat[i][j] != 1) {
            ans = max(ans, (mat[i][j] + solve2(i + 1, j, mat)) % MOD);
        }
        if (j < n - 1 and mat[i][j] != 2) {
            ans = max(ans, (mat[i][j] + solve2(i, j + 1, mat)) % MOD);
        }
        dp[i][j] = ans;
        return ans;
    }
    vector<int> findWays(vector<vector<int>>& mat) {
        memset(dp, -1, sizeof(dp));
        int ans1 = solve1(0, 0, mat);
        memset(dp, -1, sizeof(dp));
        int ans2 = solve2(0, 0, mat);
        if (ans2 < 0) ans2 = 0;
        return {ans1, ans2};
    }
};