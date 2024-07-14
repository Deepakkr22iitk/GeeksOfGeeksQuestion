//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int n=arr.size();
        int i=0,j=n-1;
        // while(i<n && arr[i]!=1)i++;
        // while(j>=0 && arr[j]!=0)j--;
        while(i<j)
        {
            if(arr[i]==1 && arr[j]==0)
            {
                arr[i]=0;
                arr[j]=1;
            }
            while(i<n && arr[i]!=1)i++;
            while(j>=0 && arr[j]!=0)j--;
        }
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
        int n = arr.size();
        Solution ob;
        ob.segregate0and1(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends