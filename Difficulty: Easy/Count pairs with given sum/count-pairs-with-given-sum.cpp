//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        unordered_map<int,int> freq;
        int n=arr.size();
        for(int i=0;i<n;++i)
        {
            freq[arr[i]]++;
        }
        int ans=0;
        for(int i=0;i<n;++i)
        {
            int req=target-arr[i];
            if(freq.find(req)!=freq.end())
            {
                if(req==arr[i]) ans+=freq[req]-1;
                else ans+=freq[req];
            }
        }
        return ans/2;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);

        cout << res << endl << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends