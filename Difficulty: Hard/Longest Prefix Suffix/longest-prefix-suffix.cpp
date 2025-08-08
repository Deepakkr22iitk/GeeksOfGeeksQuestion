class Solution {
  public:
    int getLPSLength(string &str) {
        int p = 0;  // Prefix pointer
        int s = 1;  // Suffix pointer
        int cnt = 0;  // Count of matching prefix-suffix
        int pos = 1;  // Starting position of suffix
        int n = str.size();  // Length of the string

        while(p < n && s < n) {
            if(str[p] == str[s]) {
                cnt++;
                p++;
                s++;
            } else {
                cnt = 0;
                pos++;
                s = pos;
                p = 0;
            }
        }

        return cnt;
    }
};