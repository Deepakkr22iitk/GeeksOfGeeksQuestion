class Solution {
  public:
    int f_recurr(int step,auto dp,auto v)
    {
        if(step==1) return abs(v[1]-v[0]);
        if(step==0) return 0;
        
        if(dp[step]!=-1) return dp[step];
        int last=abs(v[step]-v[step-1])+f_recurr(step-1,dp,v);
        int s_last=abs(v[step]-v[step-2])+f_recurr(step-2,dp,v);
        
        return dp[step]=min(last,s_last);
    }
    int minCost(vector<int>& height) {
        // int n=height.size();
        
        // vector<int> dp(n,-1);
        // return f_recurr(n-1,dp,height);
        
        vector<int> dp(height.size(), 0);
        
        for(int i = height.size()-2;i>=0;i--){
            int a = abs(height[i]-height[i+1]) + dp[i+1];
            int b = INT_MAX;
            if (i + 2 < height.size())
                b = abs(height[i] - height[i + 2]) + dp[i + 2];
            
            dp[i] = min(a,b);
        }
        
        return dp[0];
    }
};