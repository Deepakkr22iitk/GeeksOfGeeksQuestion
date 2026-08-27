class Solution {
  public:
    int f_recurr(vector<vector<int>> v,int r,int ind)
    {
        int n=v.size();
        if(r==n) return 0;
        
        int next=v[r][(ind+1)%3]+f_recurr(v,r+1,(ind+1)%3);
        int sec_next=v[r][(ind+2)%3]+f_recurr(v,r+1,(ind+2)%3);
        
        return min(next,sec_next);
        // return min(v[r][(ind+1)%3]+f_recurr(v,r+1,(ind+1)%3), v[r][(ind+2)%3]+f_recurr(v,r+1,(ind+2)%3));
    }
    int f_memo(vector<vector<int>>& v,
                int r,int ind,vector<vector<int>>& dp)
    {
        int n=v.size();
        if(r==n) return 0;
        if(dp[r][ind]!=-1) return dp[r][ind];

        int next=v[r][(ind+1)%3]+f_memo(v,r+1,(ind+1)%3,dp);

        int sec_next=v[r][(ind+2)%3]+f_memo(v,r+1,(ind+2)%3,dp);

        return dp[r][ind]=min(next,sec_next);
    }
    int minCost(vector<vector<int>>& mat) {
        int n=mat.size();
        
        // //solution 1
        // int first=mat[0][0]+f_recurr(mat,1,0);
        // int second=mat[0][1]+f_recurr(mat,1,1);
        // int third=mat[0][2]+f_recurr(mat,1,2);
        
        // return min(first,min(second,third));
        // // return min(mat[0][0]+f_recurr(mat,1,0),min(mat[0][1]+f_recurr(mat,1,1),mat[0][2]+f_recurr(mat,1,2)));
        
        // // solution 2
        // vector<vector<int>> dp(n,vector<int>(3, -1));
        // int first = mat[0][0] + f_memo(mat, 1, 0, dp);
        // int second = mat[0][1] + f_memo(mat, 1, 1, dp);
        // int third = mat[0][2] + f_memo(mat, 1, 2, dp);

        // return min(first, min(second, third));
        
        // // solution 3
        // vector<vector<int>> dp(n,vector<int>(3,0));

        // // Base case: Last row
        // for(int ind=0;ind<3;ind++)
        // {
        //     dp[n-1][ind] = min(mat[n-1][(ind+1)%3],mat[n-1][(ind+2)%3]);
        // }

        // // Fill from bottom to top
        // for(int r=n-2;r>= 1;r--)
        // {
        //     for(int ind=0;ind<3;ind++)
        //     {
        //         int next=mat[r][(ind+1)%3]+dp[r+1][(ind+1)%3];

        //         int sec_next=mat[r][(ind+2)%3]+dp[r+1][(ind+2)%3];

        //         dp[r][ind]=min(next,sec_next);
        //     }
        // }

        // int first=mat[0][0]+dp[1][0];
        // int second=mat[0][1]+dp[1][1];
        // int third=mat[0][2]+dp[1][2];

        // return min(first,min(second,third));
        
        // solution 4
        vector<int> prev(3);

        // First row
        prev[0]=mat[0][0];
        prev[1]=mat[0][1];
        prev[2]=mat[0][2];

        for(int r=1;r<n;r++)
        {
            vector<int> curr(3);

            curr[0]=mat[r][0]+min(prev[1],prev[2]);
            curr[1]=mat[r][1]+min(prev[0],prev[2]);
            curr[2]=mat[r][2]+min(prev[0],prev[1]);

            prev=curr;
        }

        return min(prev[0],min(prev[1],prev[2]));
    }
};