class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<int> known_by(n);
        for(int j=0;j<n;++j)
        {
            int sum=0;
            for(int i=0;i<n;++i)
            {
                sum+=mat[i][j];
            }
            known_by[j]=sum;
        }
        for(int i=0;i<n;++i)
        {
            if(accumulate(mat[i].begin(),mat[i].end(),0)==1 && known_by[i]==n)
            {
                return i;
            }
        }
        return -1;
    }
};