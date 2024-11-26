//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        int n = arr.size() ;
        int sum1 = 0 ;
        int ans = sum1 ;
        int sum = 0 ;
        for(int i = 0 ; i < n ; i ++){
            sum1 += arr[i] ;
            sum += arr[i] ;
            if(sum < 0) sum = 0 ;
            ans = max(ans , sum) ;
        }
        
        int maxi2 = 0 ;
        int sum2 = 0 ;
        
        for(int i = n - 1 ; i >= 0 ; i --){
            sum1 -= arr[i] ;
            sum2 += arr[i] ;
            maxi2 = max(maxi2 , sum2) ;
            ans = max(sum1 + maxi2 , ans) ;
        } 
        
        return ans ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends