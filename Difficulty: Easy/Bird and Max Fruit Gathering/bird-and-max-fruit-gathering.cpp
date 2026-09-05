class Solution {
  public:
    // int solve(vector<int> &v,int rem,int first, int ind)
    // {
    //     if(rem==0) return 0;
    //     int n=v.size();
    //     if(ind>=n) return 0;
        
    //     if(ind==(n-1))
    //     {
    //         if(first==1) return 0;
    //         else return v[ind];
    //     }
    //     int taken=v[ind]+solve(v,rem-1,first,ind+2);
    //     int not_taken=0+solve(v,rem,first,ind+1);
        
    //     return max(taken,not_taken);
    // }
    int maxFruits(vector<int>& arr, int m) {
        int n=arr.size();
        if(m==n) return accumulate(arr.begin(),arr.end(),0);
        
        m%=n;
        int ans=0;
        for(int i=0;i<m;++i)
        {
            ans+=arr[i];
        }
        int now=ans;
        // for(int i=m;i<n;++i)
        // {
        //     now+=(arr[i]-arr[i-m]);
        //     ans=max(ans,now);
        // }
        int ind=m;
        while(ind<2*n)
        {
            now+=(arr[ind%n]-arr[(ind-m)%n]);
            ans=max(ans,now);
            ind++;
        }
        return ans;
        // return max(arr[0]+solve(arr,m-1,1,2),solve(arr,m,0,1));
    }
};