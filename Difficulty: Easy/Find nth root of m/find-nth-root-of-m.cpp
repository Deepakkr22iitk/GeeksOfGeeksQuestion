//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int nthRoot(int n, int m) {
        int low = 1;
        int high = m;
        
        while(low<=high){
            int mid = (low+high)/2;
            int value = pow(mid,n);
            
            if (value == m) {
                return mid;  // Found the exact root
            } else if (value < m) {
                low = mid + 1;  // Increase the lower bound
            } else {
                high = mid - 1;  // Decrease the upper bound
            }
        }
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
        Solution ob;
        int ans = ob.nthRoot(n, m);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends