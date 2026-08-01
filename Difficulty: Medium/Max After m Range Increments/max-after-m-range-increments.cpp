class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        int m=k.size();
        vector<int> v(n+1,0);
        for(int i=0;i<m;++i)
        {
            v[a[i]]+=k[i];
            v[b[i]+1]-=k[i];
        }
        
        int ans=0,now=0;
        for(int i=0;i<n;++i)
        {
            now+=v[i];
            ans=max(ans,now);
        }
        
        return ans;
    }
};