class Solution {
  public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        int n=l.size();
        vector<int> ans;
        vector<int> present(n,0);
        present[0]=(r[0]-l[0]+1);
        for(int i=1;i<n;++i)
        {
            present[i]=(present[i-1]+r[i]-l[i]+1);
        }
        int q=rank.size();
        for(int i=0;i<q;++i)
        {
            int req=rank[i];
            int low=0,high=n-1;
            while(low<high)
            {
                int mid=low+(high-low)/2;
                if(req>present[mid]) low=mid+1;
                else high=mid;
            }
            ans.push_back(r[high]-(present[high]-req));
        }
        return ans;
    }
};