//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int lowerbound(vector<int> v, int len, int x)
    {
        int ans=len,low=0,high=len-1;
        while(low<=high)
        {
            int mid= low + (high-low)/2;
            if(v[mid]>=x)
            {
                ans=mid;
                high=mid-1;
            }
            else low = mid+1;
        }
        return len-ans;
    }
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n=arr.size();
        int m=arr[0].size();
        int ans=-1;
        int mx=0;
        for(int i=0;i<n;i++)
        {
            if(lowerbound(arr[i],m,1)>mx)
            {
                mx=lowerbound(arr[i],m,1);
                ans=i;
            }
        }
        return ans;
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
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends