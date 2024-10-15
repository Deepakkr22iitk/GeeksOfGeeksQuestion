//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        // int n=arr.size();
        // int i=0,j=0,ans=0;
        // int sum=arr[0];
        // while(j<n && i<=j)
        // {
        //     sum+=arr[j];
        //     if(sum<=tar)
        //     {
                
        //         if(sum==tar) ans++;
        //         j++;
        //     }
        //     else
        //     {
        //         sum-=arr[i];
        //         i++;
        //     }
        // }
        // return ans;
        
        int n = arr.size();
        unordered_map<int,int> idx;
        int sum = 0,ans=  0;
        for(int i=0;i<n;++i)
        {
            sum+=arr[i];
            if(sum==tar) ans++;
            if(idx.find(sum - tar)!=idx.end())
            {
                ans+=idx[sum-tar];
            }
            idx[sum]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int tar = stoi(ks);
        Solution obj;
        int res = obj.subArraySum(arr, tar);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends