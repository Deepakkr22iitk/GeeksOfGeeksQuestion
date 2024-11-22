//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int getMinDiff(int k, vector<int> &arr) {
        // int n=arr.size();
        // sort(arr.begin(),arr.end());
        // int sum=0;
        // for(int i=0;i<n;++i)
        // {
        //     sum+=arr[i];
        // }
        // int avg=sum/n;
        // // int low=0,high=n-1;
        // // while(low<n && arr[low]<avg) low++;
        // // while(high>=0 && arr[high]>avg) high--;
        // // if(low>0 && arr[low]>avg) low--;
        // // if(high<n-1 && arr[high]<avg) high++;
        // // int ans=(low+k)-(high-k);
        // // return ans;
        
        // int low=100001,high=-100001;
        // for(int i=0;i<n;++i)
        // {
        //     if(arr[i]<avg)
        //     {
        //         high=max(high,arr[i]+k);
        //     }
        //     else low=min(low,arr[i]-k);
        // }
        // return high-low;
        
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int low=arr[0],high=arr[n-1];
        
        int ans=high-low;
        
        for(int i=1;i<n;i++){
            low=min(arr[0]+k , arr[i]-k);
            high=max(arr[i-1]+k ,arr[n-1]-k);
            
            ans=min(ans,high - low);
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
        int k;
        cin >> k;
        cin.ignore();
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
        int res = ob.getMinDiff(k, arr);
        cout << res;

        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends