//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int rotateDelete(vector<int> &arr) {
        int n=arr.size();
        if(n==1) return arr[0];
        
        if(n&1) return arr[floor((n-3)/4)+2];
        
        else return arr[floor((n-2)/4)+1];
        // int n=arr.size();
        // vector<int> out(n,0);
        // int pass=1;
        // int now=n-1;
        // while(pass<=n/2)
        // {
        //     int count=0;
        //     while(count<=pass)
        //     {
                
        //         if(count==pass) out[now]=1;
        //         if(out[now]==0)
        //         {
        //             count++;
        //         }
        //         now--;
        //         if(now==-1) now=n-1;
        //     }
        //     pass++;
        // }
        // return 5;
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
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends