//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int f_recurr(vector<int> &coins, int sum, int idx)
    {
        if(idx==0)
        {
            if(sum%coins[0]==0) return sum/coins[0];
            else return INT_MAX / 2;
        }
        
        int not_take=0+f_recurr(coins,sum,idx-1);
        int take=INT_MAX / 2;
        if(sum>=coins[idx])
        {
            take=1+f_recurr(coins,sum-coins[idx],idx);
        }
        
        return min(take,not_take);
    }
    
    int f_memo(vector<int> &coins, vector<vector<int>> &dp, int sum, int idx)
    {
        if(idx==0)
        {
            if(sum%coins[0]==0) return sum/coins[0];
            else return INT_MAX / 2;
        }
        
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        
        int not_take=0+f_memo(coins,dp,sum,idx-1);
        int take=INT_MAX / 2;
        if(sum>=coins[idx])
        {
            take=1+f_memo(coins,dp,sum-coins[idx],idx);
        }
        return dp[idx][sum]=min(take,not_take);
    }
    int minCoins(vector<int> &coins, int sum) {
        if(sum==0) return 0;
        
        
        int n=coins.size();
        sort(coins.begin(),coins.end());
        
        // int res=f_recurr(coins,sum,n-1);
        // return res == INT_MAX / 2 ? -1 : res;
        
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        int res=f_memo(coins,dp,sum,n-1);
        return res == INT_MAX / 2 ? -1 : res;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for (int i = 0; i < m; i++)
            cin >> coins[i];

        Solution ob;
        cout << ob.minCoins(coins, v) << "\n";
    }
    return 0;
}

// } Driver Code Ends