//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    vector<vector<int>> memo; 

    int dp(int i, int j, const string& str) {
        if (i >= j) 
        {
            return 0;
        }
        
        if (memo[i][j] != -1) 
        {
            return memo[i][j];
        }
        
        if (str[i] == str[j]) {
            memo[i][j] = dp(i + 1, j - 1, str);
        } else {
            int ans = INT_MAX;
            ans = min(ans, 1 + dp(i + 1, j, str)); 
            ans = min(ans, 1 + dp(i, j - 1, str));
            memo[i][j] = ans;
        }
        return memo[i][j];
    }

    int countMin(string str) {
        int n = str.size();
        memo.resize(n, vector<int>(n, -1));
        return dp(0, n - 1, str);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends