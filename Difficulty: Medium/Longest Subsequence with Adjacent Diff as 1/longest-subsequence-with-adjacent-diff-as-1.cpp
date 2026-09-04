class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        map<int,int> len;
        int ans=0;

        for(int x:arr) 
        {
            int cur=max(len[x-1],len[x+1])+1;
            len[x]=max(len[x],cur);
            ans=max(ans,len[x]);
        }

        return ans;
    }
};