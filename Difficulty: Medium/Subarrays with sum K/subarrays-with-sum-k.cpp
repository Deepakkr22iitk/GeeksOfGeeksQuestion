//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // int helper(vector<int> &arr,int tar,int idx)
    // {
    //     int n=arr.size();
    //     if(idx==n) return 0;
    //     if(idx==(n-1)) return tar==arr[n-1];
    //     // if(idx<n)
    //     // {
    //         if(tar==arr[idx]) return 1+helper(arr,0,idx+1);
    //         return helper(arr,tar-arr[idx],idx+1);
    //     // }
    // }
    int countSubarrays(vector<int> &arr, int k) {
        // int n=arr.size();
        // int ans=0;
        // for(int i=0;i<n;++i)
        // {
        //     ans+=helper(arr,k,i);
        // }
        // return ans;
        
        unordered_map<int,int>mp;
        int count=0;
        int sum=0;
        
        mp[0]=1;
        
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            
            if(mp.find(sum-k)!=mp.end())
            {
                count+=mp[sum-k];
            }
            
            mp[sum]++;
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends