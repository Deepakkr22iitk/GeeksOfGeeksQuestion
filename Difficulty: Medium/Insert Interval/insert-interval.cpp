//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        vector<vector<int>> ans;
        int n=intervals.size();
        int flag=1;
        for(int i=0;i<n;++i)
        {
            if(flag==1 && newInterval[0]>intervals[i][1])
            {
                ans.push_back(intervals[i]);
            }
            else if(flag==0)
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                int open=min(newInterval[0],intervals[i][0]);
                int close=newInterval[1];
                int idx=i;
                while(idx<n && close>=intervals[idx][0])
                {
                    close=max(close,intervals[idx][1]);
                    idx++;
                }
                ans.push_back({open,close});
                i=--idx;
                flag=0;
            }
        }
        if(flag)
        {
            ans.push_back({newInterval[0],newInterval[1]});
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        vector<int> newInterval(2);
        cin >> newInterval[0] >> newInterval[1];

        Solution obj;
        vector<vector<int>> ans = obj.insertInterval(intervals, newInterval);
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[" << ans[i][0] << ',' << ans[i][1] << ']';
            if (i != (ans.size() - 1))
                cout << ",";
        }
        cout << "]" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends