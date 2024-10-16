//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        int n=arr.size();
        vector<int> req;
        
        for(int i=0;i<n;++i)
        {
            if(arr[i]!=(i+1)) req.push_back(arr[i]);
        }
        
        if(req.size()==0 || req.size()==3) return true;
        if(req.size()==4)
        {
            if(req[0]>req[1] && req[1]>req[2] && req[2]>req[3]) return true;
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
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends