//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;++i) sum+=arr[i];
        
        if(sum%2) return false;
        
        int req=sum/2;
        vector<bool>dp(req+1);
        dp[0]=1;
        
        for(int i=0;i<n;++i)
        {
            for(int j=req;j>=arr[i];--j) dp[j]=(dp[j] | dp[j-arr[i]]);
        }
        return dp[req];
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
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends