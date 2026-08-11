class Solution {
  public:
    bool check(const vector<vector<int>>& pre,const vector<int>& c,
        int len,int k,int n,int m) 
    {
        int x=c[0];
        int y=c[1];

        int x1=x-(len-1);
        int y1=y-(len-1);

        int x2=x+(len-1);
        int y2=y+(len-1);

        // Square goes outside matrix
        if (x1<0 || y1<0 || x2>=n || y2>=m) return false;

        // Using (n+1) x (m+1) prefix sum
        int sum=pre[x2+1][y2+1]-pre[x1][y2+1]-pre[x2+1][y1]+pre[x1][y1];

        return sum<=k;
    }

    int solve(const vector<int>& c,const vector<vector<int>>& pre,
        int k,int n,int m) 
    {
        int len=1;
        int ans=0;

        while(check(pre,c,len,k,n,m)) 
        {
            ans=len;
            len++;
        }

        if(ans==0)  return -1;

        return 2*ans-1;
    }

    vector<int> largestSquare(vector<vector<int>>& mat,
                              vector<vector<int>>& queries,int k) {

        int n = mat.size();
        int m = mat[0].size();

        // 1-indexed prefix sum
        vector<vector<int>> preMatSum(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++) 
        {
            for(int j=1; j<=m;j++) 
            {
                preMatSum[i][j]=mat[i-1][j-1]+preMatSum[i-1][j]+preMatSum[i][j-1]-preMatSum[i-1][j-1];
            }
        }

        vector<int> ans;

        for(auto& query:queries) {
            ans.push_back(solve(query,preMatSum,k,n,m));
        }

        return ans;
    }
};