class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        set<int> present;
        vector<int> ans;
        for(int i=0;i<a.size();++i)
        {
            if(present.find(a[i])==present.end())
            {
                ans.push_back(a[i]);
                present.insert(a[i]);
            }
        }
        for(int i=0;i<b.size();++i)
        {
            if(present.find(b[i])==present.end())
            {
                ans.push_back(b[i]);
                present.insert(b[i]);
            }
        }
        return ans;
    }
};