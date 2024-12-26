//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int help(vector<int> &coins,int sum, int idx,vector<vector<int>> &dp)
    {
        if(sum==0) return 0;
        if(idx==0)
        {
            if(coins[0]!=0 && (sum%coins[0])==0) return sum/coins[0];
            else return 1e9;
        }
        
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        int notTaken=0+help(coins,sum,idx-1,dp);
        int taken=1e9;
        if(sum>=coins[idx])
        {
            taken=1+help(coins,sum-coins[idx],idx,dp);
        }
        return dp[idx][sum]=min(taken,notTaken);
    }
    int minCoins(vector<int> &coins, int sum) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        sort(coins.begin(),coins.end());
        int ans=help(coins,sum,n-1,dp);
        return ans>=1e9?-1:ans;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends