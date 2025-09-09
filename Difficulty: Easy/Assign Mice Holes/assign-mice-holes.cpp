class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        int n=mices.size();
        sort(mices.begin(),mices.end());
        sort(holes.begin(),holes.end());
        
        int ans=0;
        for(int i=0;i<n;++i)
        {
            ans=max(abs(holes[i]-mices[i]),ans);
        }
        return ans;
    }
};