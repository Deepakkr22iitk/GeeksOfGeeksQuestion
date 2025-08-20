class Solution {
  public:
    bool ifPossible(int mid,auto &v,int k)
    {
        int count=0;
        int start=v[0];
        for(int i=1;i<v.size();++i)
        {
            if(v[i]-start>=mid)
            {
                count++;
                start=v[i];
                if(count==k-1) return true;
            }
        }
        return false;
    }
    int maxMinDiff(vector<int>& arr, int k) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        int high=arr[n-1]-arr[0];
        int low=0;
        int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(ifPossible(mid,arr,k))
            {
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};
