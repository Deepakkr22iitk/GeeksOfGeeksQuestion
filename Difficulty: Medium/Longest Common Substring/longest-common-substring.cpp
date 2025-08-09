class Solution {
  public:
    int longestCommonSubstr(string& text1, string& text2) {
        int n=text1.size(),m=text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for(int ind1 = 1; ind1 <= n; ind1++){
            for(int ind2 = 1; ind2 <= m; ind2++){
                if(text1[ind1 - 1] == text2[ind2 -1]) dp[ind1][ind2] =  1 + dp[ind1 - 1][ind2 - 1];

                else dp[ind1][ind2] = 0;
            }
        }
        
        int ans=0;
        for(int ind1 = 1; ind1 <= n; ind1++){
            for(int ind2 = 1; ind2 <= m; ind2++){
                // cout<<dp[ind1][ind2]<<" ";
                ans=max(ans,dp[ind1][ind2]);
            }
            // cout<<"\n";
        }

        return ans;
    }
};