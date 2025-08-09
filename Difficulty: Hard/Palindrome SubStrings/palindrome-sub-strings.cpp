class Solution {
  public:
    int countPS(string &s) {
        int n = s.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp)); //Initializing dp with -1
        int count=0;
        for(int i=0;i<n;++i)
        {
            dp[i][i]=1;
            if(i+1<n && s[i]==s[i+1])  // handling palindrome of size 2
            {
                dp[i][i+1]=1;
                count++;
            } 
        }

        for(int len=3;len<=n;++len) // considering length 'len' of palindrome starting at index 'i'
        {
            for(int i=0;i<n-len+1;++i)
            {
                int j=i+len-1; 
                if(dp[i+1][j-1]==1 && s[i]==s[j])
                {
                    dp[i][j]=1;
                    count++;
                }

            }
        }

        return count;
    }
};