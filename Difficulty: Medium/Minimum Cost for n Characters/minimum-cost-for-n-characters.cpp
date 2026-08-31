class Solution {
  public:
    int minCost(int n, int i, int d, int c) {
        vector<int> dp(n+1);
        dp[1]=i;
        for(int k=2;k<=n;++k)
        {
            // We will have 3 ways to reach to 'k'
            // 1st hai 'k-1' + i
            int mn=dp[k-1]+i;
            // 2nd hai k : agar even hai toh 'k/2' + c
            if(k%2==0)
            {
                mn=min(mn,dp[k/2]+c);
            }
            // 3rd agar odd hua
            else
            {
                // 3rd(a) 2(k/2) + c + i
                // 3rd(b) 2(k/2) + c + d
                mn=min(mn,min(dp[k/2]+c+i,dp[k/2+1]+c+d));
            }
            dp[k]=mn;
        }
        return dp[n];
    }
};
