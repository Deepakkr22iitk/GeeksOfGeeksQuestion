//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x) {
        if(v[0]>x) return -1;
        // int low=0,high=n-1;
        // while(low<=high)
        // {
        //     int mid=low+(high-low)/2;
        //     if(v[mid]==x) return mid;
        //     if(v[mid]>x) high=mid-1;
        //     else low=mid+1;
        // }
        // return low-1;
        
        int l = -1,r = n;
        while((r-l )> 1)
        {
            int mid=(l+r)/2;
            if(v[mid]<x) l=mid;
            else r=mid; 
        }
        // int k=0;
        // k=r;
        if(v[r]==x) return r;
        return r-1;
    }
};


//{ Driver Code Starts.

int main() {

    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        long long x;
        cin >> x;

        vector<long long> v;

        for (long long i = 0; i < n; i++) {
            long long temp;
            cin >> temp;
            v.push_back(temp);
        }
        Solution obj;
        cout << obj.findFloor(v, n, x) << endl;
    }

    return 0;
}
// } Driver Code Ends