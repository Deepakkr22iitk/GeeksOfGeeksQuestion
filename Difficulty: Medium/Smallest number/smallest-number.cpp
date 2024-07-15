//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        if(s>(9*d))
            return "-1";
        string ans="";
        if(s<=d)
        {
            for(int i=1;i<=d;i++){
                if(i==1){
                    ans+="1";
                    s-=1;
                }
                else if(i==d){
                    ans+=to_string(s);
                }
                else{
                    ans+="0";
                }
            }
            return ans;
        }
        int cur=s;
        for(int i=1;i<=d;i++){
            int des=(d-i)*9;
            if(i==1 && des>=cur){
                ans+="1";
                cur-=1;
            }
            else if(des>=cur){
                ans+="0";
            }
            else{
                ans+=to_string(cur-des);
                cur-=(cur-des);
            }
            if(cur==0)
                return ans;
        }
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
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends