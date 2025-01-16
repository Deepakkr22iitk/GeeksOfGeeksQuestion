//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
         int n = arr.size();
        vector<int> left(n,1),right(n,1);
        
        
        for(int i=1;i<n;i++){
            left[i] = arr[i-1] * left[i-1];
        }
        
        for(int i=n-2;i>=0;i--){
            right[i] = arr[i+1] * right[i+1];
        }
        
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            ans[i] = left[i]*right[i];
        }
        return ans;
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

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends