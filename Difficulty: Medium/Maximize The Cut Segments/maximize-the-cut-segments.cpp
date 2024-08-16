//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // Initialize a DP array with all values as INT_MIN (since we are maximizing)
        vector<int> dp(n + 1, INT_MIN);
    
        // Base case: For length 0, we can have 0 cuts
        dp[0] = 0;
    
        // Iterate over each length from 1 to n
        for (int i = 1; i <= n; ++i) {
            // Check if it's possible to make a cut of length 'a'
            if (i >= x && dp[i - x] != INT_MIN)
                dp[i] = max(dp[i], dp[i - x] + 1);
            
            // Check if it's possible to make a cut of length 'b'
            if (i >= y && dp[i - y] != INT_MIN)
                dp[i] = max(dp[i], dp[i - y] + 1);
            
            // Check if it's possible to make a cut of length 'c'
            if (i >= z && dp[i - z] != INT_MIN)
                dp[i] = max(dp[i], dp[i - z] + 1);
        }
    
        // If dp[n] is still INT_MIN, it means it's not possible to cut the rod exactly into given lengths
        return (dp[n] < 0) ? 0 : dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends