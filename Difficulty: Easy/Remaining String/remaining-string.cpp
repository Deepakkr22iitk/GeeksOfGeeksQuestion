//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string printString(string s, char ch, int count) {
        // string ans="";
        // int i=0,j=0;
        // while(j<s.size() && j<=count)
        // {
        //     if(s[i]==ch) j++;
        //     i++;
        //     if(j==count) break;
        // }
        // while(i<s.size()) {
        //     ans+=s[i]; 
        //     i++;
        // }
        // return ans;
        
        for(int i=0;i<s.length();i++){
            if(!count) return s.substr(i);
            if(s[i]==ch) count--;
        }
        return "";
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
        string s;
        char ch;
        int count;

        cin >> s >> ch >> count;
        Solution ob;
        cout << ob.printString(s, ch, count) << "\n";
    }

    return 0;
}
// } Driver Code Ends