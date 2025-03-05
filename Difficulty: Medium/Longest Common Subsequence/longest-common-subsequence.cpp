//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int lcs(string &s1, string &s2) {
        int n=s1.size();
        int m=s2.size();
        int kp[n+1][m+1];
        for(int i =0; i<=n; i++){
            for(int j = 0; j<=m; j++){
                if(i==0||j==0){
                    kp[i][j]=0;
                }
            }
        }
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s1[i-1] == s2[j-1]){
                    kp[i][j] = 1+kp[i-1][j-1];
                }
                else {
                    kp[i][j] = max(kp[i-1][j],kp[i][j-1]);
                }
            }
        }
        return kp[n][m];
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends