//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        int n=arr.size();
        vector<int> ans(n,0);
        int now=0;
        for(int i=0;i<n-1;++i)
        {
            if(arr[i]==arr[i+1] && arr[i]!=0)
            {
                ans[now]=2*arr[i];
                arr[i+1]=0;
                now++;
            }
            else if(arr[i]!=0) 
            {
                ans[now]=arr[i];
                now++;
            }
        }
        if(arr[n-2]!=arr[n-1] && arr[n-1]!=0) ans[now]=arr[n-1];
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
        Solution obj;
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends