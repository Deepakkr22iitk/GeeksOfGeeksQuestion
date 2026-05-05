class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        int n = arr.size();
        vector<int> bit(31, 0);
        for(int i: arr){
            for(int k = 0;k<31;k++){
                bit[k] += i%2;
                i>>=1;
            }
        }
        
        long long int ans = 0;
        for(int i = 0;i<31;i++){
            ans += (1LL*bit[i]*(n-bit[i])*pow(2, i));
        }
        
        return ans;
    }
};