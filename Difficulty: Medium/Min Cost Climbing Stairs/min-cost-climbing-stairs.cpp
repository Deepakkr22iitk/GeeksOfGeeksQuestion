//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    int dp[100005];
    int fn(vector<int>&a, int i){
        if(i>=a.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=1e9;
        ans=min(ans,fn(a,i+1)+a[i]);
        ans=min(ans,fn(a,i+2)+a[i]);
        return dp[i]=ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        int ans=fn(cost,0);
        ans=min(ans,fn(cost,1));
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends