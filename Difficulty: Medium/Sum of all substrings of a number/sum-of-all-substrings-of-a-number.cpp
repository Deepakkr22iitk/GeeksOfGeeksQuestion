class Solution {
  public:
    int sumSubstrings(string &s) {
        int n=s.length();
        int place=1;
        int sum=0;
        for(int i=n-1;i>=0;i--){
            int digit = s[i]-'0';
            sum+=digit*(i+1)*place;
            place=place*10+1;
        }
        return sum;
    }
};