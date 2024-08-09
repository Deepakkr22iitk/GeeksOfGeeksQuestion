//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int mod=1e9+7;
    int Maximize(vector<int> &arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        long sum = 0;  
        
        for (int i = 0; i < n; i++) {
            sum = (sum + (long) arr[i] * i) % mod;
        }
        
        return (int) sum;
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
        //  cin.ignore();
        int n = arr.size();
        Solution ob;
        cout << ob.Maximize(arr) << endl;
    }
}
// } Driver Code Ends