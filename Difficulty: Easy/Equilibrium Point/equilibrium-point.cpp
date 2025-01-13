//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        int n=arr.size();
        // int low=1,high=n-2;
        // int left=arr[0];
        // int right=arr[n-1];
        // while(low<=high)
        // {
        //     if(left<right)
        //     {
        //         left+=arr[low];
        //         low++;
        //     }
        //     else if(right<left)
        //     {
        //         right+=arr[high];
        //         high--;
        //     }
        //     else
        //     {
        //         if(high==low) return  high;
        //         else
        //         {
        //             left+=arr[low-1];
        //             low++;
        //         }
        //     }
        // }
        // return -1;
        
        int leftSum=0;
        for(int i=0;i<n-2;++i)
        {
            leftSum+=arr[i];
        }
        int rightSum=arr[n-1];
        int idx=n-2;
        while(idx>0)
        {
            if(leftSum==rightSum) return idx;
            rightSum+=arr[idx];
            idx--;
            leftSum-=arr[idx];
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends