//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        unordered_map<char,int> idx;
        int n=s.size();
        int start=0;
        int ans=0;
        for(int i=0;i<n;++i)
        {
            if(idx.find(s[i])!=idx.end())
            {
                if(idx[s[i]]<start) idx[s[i]]=i;
                else 
                {
                    ans=max(ans,i-start);
                    start=(idx[s[i]]+1);
                    idx[s[i]]=i;
                }
            }
            else 
            {
                idx[s[i]]=i;
            }
        }
        ans=max(ans,n-start);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends