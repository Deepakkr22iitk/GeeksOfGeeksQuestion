//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int pred(vector<vector<int>> &mat,int val)
    {
        int m=mat.size();
        int n=mat[0].size();
        
        int res=0;
        
        for(int i=0;i<m;++i)
        {
            int low=0,high=n-1;
            int ans=m;
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                if(mat[i][mid]>val)
                {
                    ans=mid;
                    high=mid-1;
                }
                else low=mid+1;
            }
            res+=ans;
        }
        return res;
    }
    int median(vector<vector<int>> &mat) {
        int m=mat.size();
        int n=mat[0].size();
        
        int req=(m*n)/2;
        
        int low=INT_MAX,high=0;
        for(int i=0;i<m;++i)
        {
            low=min(low,mat[i][0]);
            high=max(high,mat[i][n-1]);
        }

        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(pred(mat,mid)<=req) low=mid+1;
            else high=mid-1;
        }
        
        return low;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends