//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
    int f_recurr(vector<int> &arr,int n,int idx)
    {
        if(idx>=n) return 0;
        int looted=0,not_looted=0;
        looted=arr[idx]+f_recurr(arr,n,idx+2);
        not_looted=0+f_recurr(arr,n,idx+1);
        
        return max(looted,not_looted);
    }
    
    int f_memo(vector<int> &arr,vector<int> &dp,int n,int idx)
    {
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int looted=0,not_looted=0;
        looted=arr[idx]+f_memo(arr,dp,n,idx+2);
        not_looted=0+f_memo(arr,dp,n,idx+1);
        
        return dp[idx]=max(looted,not_looted);
    }
    int findMaxSum(vector<int>& arr) {
        int n=arr.size();
        // return f_recurr(arr,n,0);
        
        vector<int> dp(n,-1);
        return f_memo(arr,dp,n,0);
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

        Solution ob;
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends