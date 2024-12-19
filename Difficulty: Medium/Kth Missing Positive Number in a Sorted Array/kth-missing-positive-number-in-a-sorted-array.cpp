//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int n=arr.size();
        // int last=0,idx=0,miss=0;
        // while(idx<n && miss+(arr[idx]-last-1)<k)
        // {
        //     miss+=(arr[idx]-last-1);
        //     last=arr[idx];
        //     idx++;
        // }
        // return arr[--idx]+k-miss;
        
        if(k<=arr[0]-1) return k;
        if(k>(arr[n-1]-n)) return arr[n-1]+(k-(arr[n-1]-n));
        int low=0,high=n-1,ans=-1;
        while(low<=high)
        {
            // if(low==high) 
            // {
            //     int prev_diff=(arr[low-1]-low);
            //     return arr[low-1]+k-prev_diff;
            // }
            int mid=low+(high-low)/2;
            if((arr[mid]-(mid+1))>=k)
            {
                ans=mid;
                high=mid-1;
            }
            // if((arr[mid]-mid-1)>k) high=mid-1;
            else low=mid+1;
        }
        // if((arr[ans]-(ans+1))==k) return arr[ans]-1;
        return arr[ans]-((arr[ans]-(ans+1))-k)-1;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.kthMissing(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends