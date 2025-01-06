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
                ans+=freq[req];
                if(arr[i]==req) ans--;
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
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends