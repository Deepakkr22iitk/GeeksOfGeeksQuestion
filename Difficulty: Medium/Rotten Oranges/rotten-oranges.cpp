//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2) q.push({i,j});
                else if(mat[i][j]) fresh++;
            }
        }
        int time=0;
        vector<vector<int>>vis(n,vector<int>(m));
        vector<pair<int,int>>edge={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int x=q.size();
            time++;
            while(x--){
                auto r=q.front();
                q.pop();
                for(auto ch:edge){
                    int a=r.first+ch.first,b=r.second+ch.second;
                    if(a>=0 && a<n && b>=0 && b<m
                        && vis[a][b]==0 && mat[a][b]==1){
                            fresh--;
                            q.push({a,b});
                            vis[a][b]=1;
                    }
                }
            }
        }
        if(fresh==0) return max(0,time-1);
        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends