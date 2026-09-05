class Solution {
  public:
    int solve(vector<int> &v,int ind,vector<int> &dp)
    {
        int n=v.size();
        if(ind>=n) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        int taken=0,not_taken=0;
        taken=v[ind]+solve(v,ind+2,dp);
        not_taken=0+solve(v,ind+1,dp);
        
        return dp[ind]=max(taken,not_taken);
    }
    int maxDiffSum(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return 0;
        // if(n==2) return max(arr[0],arr[1])-1;
        
        vector<int> contribution(n,0);
        contribution[0]=arr[0]-1;
        contribution[n-1]=arr[n-1]-1;
        for(int i=1;i<n-1;++i)
        {
            contribution[i]=2*(arr[i]-1);
        }
        // Memoization
        vector<int> dp(n,-1);
        int ans=solve(contribution,0,dp);
        return ans;
        
        
        
        // Space Optimization
        // vector<int> dp(n+2,0);
        // for(int i=n-1;i>=0;i--)
        // {
        //     dp[i]=max(contribution[i]+dp[i+2],dp[i+1]);
        // }

        return dp[0];
    }
};