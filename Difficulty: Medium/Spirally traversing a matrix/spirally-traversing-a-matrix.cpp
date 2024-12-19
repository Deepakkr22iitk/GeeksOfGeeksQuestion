//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        int n=mat.size(),m=mat[0].size();
        vector<int> ans;
        int sr=0,sc=0,er=n-1,ec=m-1;
        while(sr<=er && sc<=ec)
        {
            for(int j=sc;j<=ec;++j)
            {
                ans.push_back(mat[sr][j]);
            }
            sr++;
            for(int i=sr;i<=er;++i)
            {
                ans.push_back(mat[i][ec]);
            }
            ec--;
            for(int j=ec;j>=sc && sr<=er;--j)
            {
                ans.push_back(mat[er][j]);
            }
            er--;
            for(int i=er;i>=sr && sc<=ec;--i)
            {
                ans.push_back(mat[i][sc]);
            }
            sc++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends