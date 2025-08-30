class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int a = 0, b = n - 1;
    
        // Step 1: Find potential celebrity
        while (a < b) {
            if (mat[a][b] == 1) {
                // a knows b -> a cannot be celebrity
                a++;
            } else {
                // a does not know b -> b cannot be celebrity
                b--;
            }
        }
    
        int cand = a; // only candidate left
    
        // Step 2: Verify candidate
        for (int i = 0; i < n; i++) {
            if (i == cand) continue;
    
            // celebrity should not know anyone
            if (mat[cand][i] == 1) return -1;
    
            // everyone should know celebrity
            if (mat[i][cand] == 0) return -1;
        }
    
        return cand;
    }
};