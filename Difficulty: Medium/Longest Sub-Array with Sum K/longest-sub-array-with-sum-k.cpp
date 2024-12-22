//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        // sum till that ind,ind
        unordered_map<int,int> mp;
        mp[0]=-1;
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;++i)
        {
            sum+=arr[i];
            if(mp.find(sum)==mp.end()) mp[sum]=i;
        }
        int ans=0;
        for(int i=n-1;i>=0;--i)
        {
            if(mp.find(sum-k)!=mp.end())
            {
                ans=max(ans,i-mp[sum-k]);
            }
            sum-=arr[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.lenOfLongestSubarr(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends