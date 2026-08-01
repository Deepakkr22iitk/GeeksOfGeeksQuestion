class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        int m=k.size();
        vector<int> preSum(n+1,0);
        
        for(int i=0;i<m;++i)
        {
            preSum[a[i]]+=k[i];
            preSum[b[i]+1]-=k[i];
        }
        
        int ans=0,curr=0;
        for(int i=0;i<n;++i)
        {
            curr+=preSum[i];
            ans=max(ans,curr);
        }
        
        return ans;
    }
};