class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans=0;
        int p=left.size();
        if(p>0)
        {
            for(int i=0;i<p;++i)
            {
                ans=max(ans,left[i]);
            }
        }
        int m=right.size();
        if(m>0)
        {
            for(int i=0;i<m;++i)
            {
                ans=max(ans,n-right[i]);
            }
        }
        return ans;
    }
};