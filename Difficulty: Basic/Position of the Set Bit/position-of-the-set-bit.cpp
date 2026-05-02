class Solution {
  public:
    int findPosition(int n) {
        if(n==0) return -1;
        if(n==1) return 1;
        int ans=1;
        while(n>1)
        {
            if(n&1==1) return -1;
            n=n>>1;
            ans++;
        }
        return ans;
    }
};