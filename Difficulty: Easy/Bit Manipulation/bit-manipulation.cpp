//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
        int ithBit = (num >> (i - 1)) & 1;  // Get the ith bit
        int setIthBit = num | (1 << (i - 1));  // Set the ith bit
        int clearIthBit = num & (~(1 << (i - 1)));  // Clear the ith bit
        
        cout<<ithBit<<" "<<setIthBit<<" "<<clearIthBit;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends