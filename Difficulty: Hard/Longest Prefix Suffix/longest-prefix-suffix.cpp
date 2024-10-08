//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int lps(string str) {
        int n = str.size();
        vector<int> kmp(n);
        
        int i = 0;
        for(int j = 1; j < n; j++) {
            if(str[i] == str[j]) {
                kmp[j] = ++i;
            }
            else {
                while((--i) >= 0) {
                    i = kmp[i];
                    if(str[i] == str[j]) break;
                }
                kmp[j] = ++i;
            }
        }
        return kmp[n - 1];
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends