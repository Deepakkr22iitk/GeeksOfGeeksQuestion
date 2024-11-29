//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        int n=s1.size(),m=s2.size();
        int ind=0;
        string ans;
        for(int i=0;i<max(n,m);i++){
            if(i<n) ind+=s1[i]-'0';
            if(i<m) ind+=s2[i]-'0';
            ans.push_back ('0'+ind%2);
            ind>>=1;
        }
        ans.push_back ('0'+ind);
        while(ans.back()=='0') ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends