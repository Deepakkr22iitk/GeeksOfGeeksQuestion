//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        long long int l=1,h=n,m=0,count;
        while(l<=h)
        {
            m=(l+h)/2;
            if(m*m==n)
            return m;
            else if(m*m<n)
            {
                count=m;
                l=m+1;
            }
            else
            h=m-1;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends