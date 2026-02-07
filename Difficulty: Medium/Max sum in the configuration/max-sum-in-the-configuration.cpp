class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n=arr.size();
        
        int ans=0,total=0;
        for(int i=0;i<n;++i)
        {
            ans+=(arr[i]*i);
            total+=arr[i];
        }
        int res=ans;
        int ind=0;
        // int sum=0;
        for(int i=1;i<n;++i)
        {
            // ans=max(ans,ans+total-arr[n-i]*n);
            // ans+=max(0,total-(arr[n-i]*n));
            // if(total>arr[n-i]*n)
            // {
            //     // ind=i;
            //     ans+=(total-(n*arr[n-i]));
            // }
            res+=(total-(n*arr[n-i]));
            ans=max(ans,res);
        }
        // cout<<ind<<"\n";
        return ans;
    }
};