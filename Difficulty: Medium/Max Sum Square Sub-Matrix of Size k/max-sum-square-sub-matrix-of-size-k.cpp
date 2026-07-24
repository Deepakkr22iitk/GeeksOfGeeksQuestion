class Solution {
  public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>>row(mat.size(),vector<int>(mat[0].size()));
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                if(j==0)
                row[i][j]=mat[i][j];
                else
                row[i][j]=row[i][j-1]+mat[i][j];
            }
        }
        int maxi=INT_MIN;
        int sc=0;
        while(sc<=mat[0].size()-k)
        {
            int sr=0;
            while(sr<=mat.size()-k)
            {
                int s=0;
                for(int i=sr;i<sr+k;i++)
                {
                    if(sc==0)
                    s=s+row[i][sc+k-1];
                    else
                    s=s+row[i][sc+k-1]-row[i][sc-1];
                }
                maxi=max(maxi,s);
                sr++;
            }
            sc++;
        }
        return maxi;
    }
};