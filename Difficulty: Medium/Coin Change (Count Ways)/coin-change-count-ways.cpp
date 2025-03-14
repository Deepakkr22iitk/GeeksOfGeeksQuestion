//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int i, int n, int t, int sum, vector<int>&coins, 
    vector<vector<int>>&dp){
        if(t==sum) return 1;
        if(i>=n) return 0;
        if(dp[i][t]!=-1) return dp[i][t];
        int take=0;
        if(t+coins[i]<=sum) take=solve(i, n, t+coins[i], sum, coins, dp);
        return dp[i][t]=take+solve(i+1, n, t, sum, coins, dp);
    }
    int count(vector<int>& coins, int sum) {
        int n=coins.size();
        vector<vector<int>>dp(n+1, vector<int>(sum+1, -1));
        return solve(0, n, 0, sum, coins, dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends