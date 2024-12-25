//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-1;++i)
        {
            int req=target-arr[i];
            int low=i+1,high=n-1;
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                if(arr[mid]==req) return true;
                if(arr[mid]<req) low=mid+1;
                else high=mid-1;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.twoSum(arr, x);
        cout << (ans ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends