class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> range;
        int n =arr.size();
        range[arr[0]].push_back(0);
        int prev=0;
        for(int i=0;i<n;i++){
            if(arr[prev]==arr[i])continue;
            range[arr[prev]].push_back(i-1);
            prev=i;
            range[arr[prev]].push_back(i);
        }
        range[arr[n-1]].push_back(n-1);
        
        int q=queries.size();
        vector<int> ans(q);
        for(int i=0;i<q;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int x=queries[i][2];
            if(range.count(x)==0||range[x][0]>r||range[x][1]<l){
                ans[i]=0;
                continue;
            }
            ans[i]=min(range[x][1],r)-max(range[x][0],l)+1;
        }
        return ans;
    }
};