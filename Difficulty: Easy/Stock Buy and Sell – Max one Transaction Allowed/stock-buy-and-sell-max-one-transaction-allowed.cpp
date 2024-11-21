//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        vector<int> lowprice;
        int n=prices.size();
        int low=10001;
        int ans=0;
        for(int i=0;i<n;++i)
        {
            if(prices[i]<low) low=prices[i];
            lowprice.push_back(low);
        }
        
        for(int i=n-1;i>=0;--i)
        {
            ans=max(ans,abs(lowprice[i]-prices[i]));
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
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends