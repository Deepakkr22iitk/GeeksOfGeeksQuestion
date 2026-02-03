class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n=prices.size();
        vector<int> preBuy(n-1,0);
        int tillNow=1e5+1;
        for(int i=0;i<n-1;++i)
        {
            tillNow=min(tillNow,prices[i]);
            preBuy[i]=tillNow;
        }
        int ans=0;
        for(int i=1;i<n;++i)
        {
            ans=max(ans,prices[i]-preBuy[i-1]);
        }
        return ans;
    }
};
