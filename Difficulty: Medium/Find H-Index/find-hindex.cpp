class Solution {
  public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int ans=0,n=citations.size();
        for(int i=0;i<n;++i)
        {
            if(citations[i]>=n-i)
            {
                ans=max(ans,min(n-i,citations[i]));
            }
        }
        return ans;
    }
};