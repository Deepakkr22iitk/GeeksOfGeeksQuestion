class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> idx;
        for(int i=0;i<n;++i)
        {
            idx.push_back({arr[i],i});
        }
        sort(idx.begin(),idx.end());
        vector<int> ans(n);
        int ind=idx[0][1];
        int num=idx[0][0];
        ans[ind]=-1;
        for(int i=1;i<n;++i)
        {
            if(idx[i][0]>num)
            {
                if(ind>idx[i][1]) ans[idx[i][1]]=ind;
                else ans[idx[i][1]]=-1;
            }
            else ans[idx[i][1]]=-1;
            ind=max(ind,idx[i][1]);
        }
        // ans[n-1]=-1;
        return ans;
    }
};