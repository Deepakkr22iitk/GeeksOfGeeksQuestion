//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    //       <--decrease----
    //     ^ # # # # # # # ★ |
    //     | # . . . . . . . |
    //    se . . . . . . . . in
    //    ea . . . . . . . . cr
    //    cr .             . ea
    //    de .             . se
    //     | .             # |
    //     | ★ # # # # # # # \/
    //       ---increase-->
    
    //       only ★ can be the starting points
    bool matSearch(vector<vector<int>> &mat, int x) {
        // TC->O(n+m) as these are the max number of steps can be taken
        int m=mat.size();
        int n=mat[0].size();
        int row=0,col=n-1;
        while(row<m && col>=0)
        {
            if(mat[row][col]==x) return true;
            if(mat[row][col]<x) row++;
            else col--; 
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));
        int x;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }
        cin >> x;
        Solution ob;
        bool an = ob.matSearch(matrix, x);
        if (an)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends