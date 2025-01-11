//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n=arr.size();
        int l=0;
        int h=n-1;
        int leftMax= arr[0];
        int rightMax=arr[n-1];
        int ans=0;
        while(l<h) 
        {
           if( arr[l]<arr[h] ) 
           {
               ans+=min(leftMax,rightMax)-arr[l];
               l++;
               leftMax=max(leftMax,arr[l]);
           } 
           else 
           {
               ans+=min(leftMax,rightMax)-arr[h];
               h--;
               rightMax=max(rightMax,arr[h]);
           }
        }
        return ans;
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
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends