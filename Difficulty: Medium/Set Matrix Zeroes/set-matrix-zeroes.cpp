//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int n=mat.size();
        int m=mat[0].size();
        set<int> col;
        vector<int> row;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(mat[i][j]==0)
                {
                    col.insert(j);
                    row.push_back(i);
                }
            }
        }
        for(int i=0;i<row.size();++i)
        {
            for(int j=0;j<m;++j)
            {
                mat[row[i]][j]=0;
            }
        }
        for(int j=0;j<m;++j)
        {
            if(col.find(j)!=col.end())
            {
                for(int i=0;i<n;++i)
                {
                    mat[i][j]=0;
                }
            }
        }
        return ;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends