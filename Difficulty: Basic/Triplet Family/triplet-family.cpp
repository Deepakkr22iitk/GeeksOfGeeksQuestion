//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-2;++i)
        {
            for(int j=i+1;j<n-1;++j)
            {
                int k=j+1;
                while(k<n && arr[k]<=(arr[i]+arr[j]))
                {
                    if(arr[k]==(arr[i]+arr[j])) return true;
                    k++;
                }
            }
        }
        return false;
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
        Solution obj;
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends