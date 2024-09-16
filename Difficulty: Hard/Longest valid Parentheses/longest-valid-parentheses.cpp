//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string& str) {
        int maxi = 0 ;
        int left = 0;
        int right = 0;
        int n  = str.length();
        for(int i=0;i<n;i++){
            if(str[i] == '(') left++;
            else if(str[i] == ')') right++;
            if(left == right) maxi = max(right+left,maxi);
            else if(right > left) right=0,left=0;
        }
        left = 0,right=0;
        for(int i=n-1;i>=0;i--){
            if(str[i] == '(') left++;
            else if(str[i] == ')') right++;
            if(left == right) maxi = max(right+left,maxi);
            else if(left > right) right=0,left=0;
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends