//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool help(vector<int> &v,int tar)
    {
        int low=0,high=v.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(v[mid]==tar) return true;
            if(v[mid]>tar) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        int n=mat.size();
        sort(mat.begin(),mat.end());
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(mat[mid][0]>x) high=mid-1;
            else low=mid+1;
        }
        for(int i=0;i<=high;++i)
        {
            if(help(mat[i],x)) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchRowMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends