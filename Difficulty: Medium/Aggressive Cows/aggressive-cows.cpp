// User function Template for C++

class Solution {
  public:
    bool pred(vector<int> &stalls,int k,int req)
    {
        int count=1,n=stalls.size();
        int last=stalls[0];
        for(int i=1;i<n;++i)
        {
            while(i<n && stalls[i]<(last+req)) i++;
            if(i<n && stalls[i]>=(last+req))
            {
                count++;
                last=stalls[i];
            }
        }
        return count>=k;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(),stalls.end());
        int n=stalls.size();
        int low=0,high=stalls[n-1]+1;
        int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(pred(stalls,k,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return high;
    }
};
