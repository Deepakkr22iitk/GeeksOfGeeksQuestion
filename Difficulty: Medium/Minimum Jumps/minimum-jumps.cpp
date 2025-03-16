//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int jump = 0;
        int n = arr.size();
        int maxi=0;
        int mrange=0;
        
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]+i);
            if(mrange==i){
                mrange=maxi;
                jump++;
                if(mrange>=n-1)
                {
                  return jump;
                }
            }
        }
        
        return -1;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends