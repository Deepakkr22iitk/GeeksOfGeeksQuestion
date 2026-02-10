class Solution {
  public:
    int possible(int s,vector<int> v)
    {
        int n=v.size();
        int hour=0;
        for(int i=0;i<n;++i)
        {
            hour+=((v[i]+s-1)/s);
        }
        return hour;
    }
    int kokoEat(vector<int>& arr, int k) {
        int low=1,high=*max_element(arr.begin(),arr.end());
        int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(possible(mid,arr)<=k)
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};