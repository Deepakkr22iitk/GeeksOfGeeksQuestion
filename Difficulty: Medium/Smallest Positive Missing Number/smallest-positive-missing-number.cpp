//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        int n=arr.size();
        
        // sort(arr.begin(),arr.end());
        // int idx=0,ans=1;
        // while(idx<n)
        // {
        //     if(arr[idx]==ans) ans++;
        //     idx++;
        // }
        // return ans;
        
        int mx=INT_MIN;
        for(int i=0;i<n;i++) 
        {
            if(arr[i]<=0)
                arr[i]=0;
            mx=max(mx,arr[i]);
        }
        mx=mx+1;
        for(int i=0;i<n;i++) 
        {
            if(arr[i]>0) 
            {
                int ind=arr[i]%mx-1;
                if(ind<n && ind>=0) arr[ind]+=mx;
            }
        }
        for(int i=0;i<n;i++)
            if(arr[i]<mx)
                return i+1;
        return n+1;
    }
};

//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends