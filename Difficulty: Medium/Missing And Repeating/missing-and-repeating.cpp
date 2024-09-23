//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n=arr.size();

        vector<int> ans(2);
        
        
        if(n==1)
        {
            return ans;
        }
           
        for(int i=0; i<n; i++)
        { 
            int index=abs(arr[i])-1;
        
        
            if(arr[index]<0)
            {
               ans[0]=abs(arr[i]);
                
            }
            else
            {
                arr[index]=-arr[index];
            } 
        } 
            
        for(int i=0; i<n; i++)
        {
            if(arr[i]>0)
            {
                ans[1]=i+1;
                break;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends