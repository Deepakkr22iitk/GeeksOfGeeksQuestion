//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool pred(vector<int> &arr,int k,int req)
    {
        int count=0,n=arr.size();
        int sum=0;
        for(int i=0;i<n;++i)
        {
            if(arr[i]>req) return false;
            
            if((sum+arr[i])<=req)
            {
                sum+=arr[i];
            }
            else
            {
                count++;
                sum=arr[i];
            }
        }
        
        count++; // To cover the last subarray ending with (n-1)
        
        return (count<=k);
    }
    int findPages(vector<int> &arr, int k) {
        int n=arr.size();
        if(k>n) return -1;
        int mx=arr[0];
        for(int i=0;i<n;++i) mx=max(mx,arr[i]);
        
        if(k==n) return mx;
        
        int ans=-1;
        int low=0;
        int high=accumulate(arr.begin(),arr.end(),0);
        // int high=0;
        // for(int i=0;i<n;i++){
        //     high+=arr[i];
        // }
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(pred(arr,k,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else 
            {
                low=mid+1;
            }
        }
        return ans;
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
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends