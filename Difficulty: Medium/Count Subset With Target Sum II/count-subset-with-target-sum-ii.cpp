class Solution {
  public:
    void subsetSum(int i,int r,int sum,vector<int> &arr,map<int,int> &mp)
    {
        if(i==r)
        {
            mp[sum]++;
            return ;
        }
        
        subsetSum(i+1,r,sum+arr[i],arr,mp);
        subsetSum(i+1,r,sum,arr,mp);
        
        return ;
    }
    int countSubset(vector<int> &arr, int k) {
        int n=arr.size();
        
        // int ans=0;
        // for(int i=0;i<(1<<n);++i)
        // {
        //     int sum=0;
        //     for(int j=0;sum<=k && j<n;++j)
        //     {
        //         if(i&(1<<j)) sum+=arr[j];
        //     }
        //     if(sum==k) ans++;
        // }
        // return ans;
        
        int mid=n/2;
        map<int,int> lmp;
        map<int,int> rmp;
        
        subsetSum(0,mid,0,arr,lmp);
        subsetSum(mid,n,0,arr,rmp);
        
        int cnt=0;
        for(auto p:lmp)
        {
            if(rmp[k-p.first])
            {
                cnt+=p.second*rmp[k-p.first];
            }
        }
        
        return cnt;
    }
};