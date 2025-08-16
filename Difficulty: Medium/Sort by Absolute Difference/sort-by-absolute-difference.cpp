class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        vector<vector<int>> v;
        int n=arr.size();
        for(int i=0;i<n;++i)
        {
            v.push_back({abs(x-arr[i]),i});
        }
        sort(v.begin(),v.end());
        vector<int> updated;
        for(int i=0;i<n;++i)
        {
            updated.push_back(arr[v[i][1]]);
        }
        arr=updated;
        return ;
    }
};