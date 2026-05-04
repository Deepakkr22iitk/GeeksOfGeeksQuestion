class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        int rev=0,org=n;
            while(n){
                rev=(rev<<1)|(n&1);
                n>>=1;
            }
            
            return org==rev;
    }
};