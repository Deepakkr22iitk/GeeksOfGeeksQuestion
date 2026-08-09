class Solution {
  public:
    int dfs(vector<vector<int>>& mat,int i,int last,vector<vector<int>>&dp)
    {
        int n=mat.size();
        
        if(i==n-1) return mat[i][last];
        
        if(dp[i][last]!=-1) return dp[i][last];
        
        int best=0;
        for(int ind=0;ind<n;++ind)
        {
            if(ind!=last)
            {
                best=max(best,dfs(mat,i+1,ind,dp));
            }
        }
        return dp[i][last]=mat[i][last]+best;
    }
    int zigzagSequence(vector<vector<int>>& mat) {
        int n=mat.size();
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        int ans=0;
        for(int ind=0;ind<n;++ind)
        {
            ans=max(ans,dfs(mat,0,ind,dp));
        }
        
        return ans;
    }
};