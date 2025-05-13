//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int nCr(int n, int r) {
        if(n<r){
            return 0;
        }
        vector<int> v1(r+1,1);
        int temp = 1;
        for(int i = 2;i<=n;i++){
            for(int j = 1;j<i;j++){
                if(j>r){
                    continue;
                }
                int temp2 = v1[j];
                v1[j] = (v1[j] + temp) % 1000000007;
                temp = temp2;
            }
            temp = 1;
        }
        return v1[r];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends