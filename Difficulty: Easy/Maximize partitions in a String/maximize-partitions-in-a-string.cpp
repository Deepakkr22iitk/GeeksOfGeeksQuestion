//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        int n = s.length();
        unordered_map<char,int> mp; //SC O(N)
        
        for(int i=0; i<n; i++) { // O(N)
            mp[s[i]] = i;
        }
        
        int count = 0;
        
        unordered_map<char,int> pos; // O(N) //worst case
        
        for(int i=0; i<n; i++) { // O(N)
            pos[s[i]] = i;
            
            if(pos[s[i]] == mp[s[i]]) {
                pos.erase(s[i]);
                
                if(pos.size() == 0) {
                    count++;
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends