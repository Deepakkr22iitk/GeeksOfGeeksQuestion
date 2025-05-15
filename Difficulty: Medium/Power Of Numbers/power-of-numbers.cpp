//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int reverse(int n)
    {
        int ans=0;
        while(n>0)
        {
            ans*=10;
            ans+=(n%10);
            n/=10;
        }
        return ans;
    }
    int cal(int a,int b)
    {
        if(b==0) return 1;
        int half=cal(a,b/2);
        if(b%2==0) return half*half;
        else return half*half*a;
    }
    int reverseExponentiation(int n) {
        int b=reverse(n);
        return cal(n,b);
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T; // test cases

    while (T--) {
        int n;
        cin >> n; // input N

        Solution ob;
        // power of the number to its reverse
        int ans = ob.reverseExponentiation(n);
        cout << ans << endl;
    }

    return 0;
}

// } Driver Code Ends