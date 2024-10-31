//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int i=0,j=n-1;
        long long ans=0;
        // while(i<j)
        // {
        //     ans+=(arr[j]-arr[i]);
        //     i++;
        //     ans+=(arr[j]-arr[i]);
        //     j--;
        //     ans+=(arr[j]-arr[i]);
        // }
        // if(j==i)
        // {
        //     ans+=(arr[j]-arr[j-1]);
        //     ans+=(arr[j+1]-arr[j]);
        // }
        // else ans+=(arr[i]-arr[j]);
        
        vector<int> v;
        while(i<j)
        {
            v.push_back(arr[i]);
            v.push_back(arr[j]);
            j--;
            i++;
        }
        if(i==j) v.push_back(arr[i]);
        int idx=1;
        ans+=(v[n-1]-v[0]);
        while(idx<n) 
        {
            ans+=abs(v[idx]-v[idx-1]);
            idx++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends