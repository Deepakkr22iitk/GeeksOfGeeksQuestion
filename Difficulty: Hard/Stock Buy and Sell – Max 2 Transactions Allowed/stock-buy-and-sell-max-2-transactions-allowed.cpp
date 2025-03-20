//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int dp[100001][2][3];
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
            memset(dp, 0, sizeof(dp));
            
            for(int i=n-1; i>=0; i--){
                for(int canbuy =0; canbuy<=1; canbuy++){
                    for(int count=1; count<=2; count++){
                        int ans = 0;
                        if(canbuy){
                            ans = -prices[i]+dp[i+1][0][count];
                            ans = max(ans, dp[i+1][1][count]);
                        }
                        else{
                            ans = prices[i] + dp[i+1][1][count-1];
                            ans = max(ans, dp[i+1][0][count]);
                        }
                        
                        dp[i][canbuy][count] = ans;
                    }
                }
            }
            
            return dp[0][1][2];
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends