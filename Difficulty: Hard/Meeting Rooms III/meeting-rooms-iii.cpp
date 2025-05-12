//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        sort(meetings.begin(),meetings.end());
        vector<int> arr(n,0);
        set<int> st;
        for(int i=0;i<n;i++) st.insert(i);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i=0;i<meetings.size();i++){
            int start = meetings[i][0], end = meetings[i][1];
            while(!pq.empty() && pq.top()[0]<=start){
                auto v = pq.top();
                pq.pop();
                int t = v[0], r = v[1];
                st.insert(r);
            }
            if(st.empty()){
                if(!pq.empty()){
                    auto v = pq.top();
                    pq.pop();
                    int t = v[0], r = v[1];
                    arr[r]++;
                    pq.push({t-start+end,r});
                }
            }else{
                auto it = st.begin();
                pq.push({end,*it});
                arr[*it]++;
                st.erase(it);
            }
        }
        int maxi = -1, ans = -1;
        for(int i=0;i<n;i++){
            if(maxi<arr[i]){
                maxi = arr[i];
                ans = i;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends