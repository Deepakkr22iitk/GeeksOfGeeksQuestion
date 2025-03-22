//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int f_recurr(vector<int> &arr,int n, int idx)
    {
        if(idx>=n) return 0;
        int looted=0,not_looted=0;
        looted=arr[idx]+f_recurr(arr,n,idx+2);
        not_looted=0+f_recurr(arr,n,idx+1);
        
        return max(looted,not_looted);
    }
    
    int f_memo(vector<int> &arr,vector<int> &dp,int n, int idx)
    {
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int looted=0,not_looted=0;
        looted=arr[idx]+f_memo(arr,dp,n,idx+2);
        not_looted=0+f_memo(arr,dp,n,idx+1);
        
        return dp[idx]=max(looted,not_looted);
    }
    int maxValue(vector<int>& arr) {
        int n=arr.size();
        // return max(f_recurr(arr,n,1),f_recurr(arr,n-1,0));
        
        vector<int> dp1(n,-1);
        int s1=f_memo(arr,dp1,n,1);
        vector<int> dp2(n,-1);
        int s2=f_memo(arr,dp2,n-1,0);
        return max(s1,s2);
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends