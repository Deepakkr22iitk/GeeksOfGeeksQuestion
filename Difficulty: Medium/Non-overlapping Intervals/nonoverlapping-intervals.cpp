//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        int n=intervals.size();
        vector <pair<int,int>> v;
        for(auto it:intervals)
        {
            v.push_back({it[1],it[0]});
        }
        
        pair <int,int> temp={INT_MIN,INT_MIN};
        int count=0;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            if(v[i].second>=temp.first)
            {
                count++;
                temp=v[i];
            }
        }
        return n-count;
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
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends