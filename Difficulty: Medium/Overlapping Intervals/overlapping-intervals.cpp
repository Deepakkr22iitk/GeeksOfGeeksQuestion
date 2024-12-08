//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            int open=arr[i][0];
            int idx=i+1;
            int close=arr[i][1];
            while(idx<n && arr[idx][0]<=close) 
            {
                close=max(close,arr[idx][1]);
                i=idx;
                idx++;
            }
            idx--;
            i=idx;
            ans.push_back({open,close});
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends