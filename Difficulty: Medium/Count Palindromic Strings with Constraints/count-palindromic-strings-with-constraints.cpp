class Solution {
  public:
    const int mod=1e9+7;
    int palindromicStrings(int n, int k) {
        long long ans=0;
        long long ways=1;

        for (int len=1;len<=n;len++) {

            int required=(len+1)/2;

            if (required>k)
                break;

            // Calculate P(k, required)
            long long total=1;

            for (int i=0;i<required;i++) {
                total=(total*(k-i))%mod;
            }

            ans=(ans+total)%mod;
        }

        return ans;
    }
};