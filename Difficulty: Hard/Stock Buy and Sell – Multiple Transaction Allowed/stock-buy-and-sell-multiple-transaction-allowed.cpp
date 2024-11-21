//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int n=prices.size();
        int ans=0,buy=prices[0],idx=0;
        while(idx<n)
        {
            if(prices[idx]<buy) buy=prices[idx];
            if(idx==n-1) ans+=(prices[n-1]-buy);
            if(idx<n-1 && prices[idx]>prices[idx+1])
            {
                ans+=(prices[idx]-buy);
                idx++;
                buy=prices[idx];
            }
            idx++;
        }
        return ans;
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
        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res;

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends