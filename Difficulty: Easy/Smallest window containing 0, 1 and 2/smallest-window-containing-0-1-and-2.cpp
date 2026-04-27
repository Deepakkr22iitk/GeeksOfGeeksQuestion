class Solution {
  public:
    int smallestSubstring(string s) {
        int n = s.length();
        int z = 0, o = 0, t = 0;
        int left = 0, minlen = INT_MAX;
    
        for (int right = 0; right < n; right++) {
            if (s[right] == '0') z++;
            else if (s[right] == '1') o++;
            else if (s[right] == '2') t++;
    
            while (z > 0 && o > 0 && t > 0) {
                minlen = min(minlen, right - left + 1);
    
                if (s[left] == '0') z--;
                else if (s[left] == '1') o--;
                else if (s[left] == '2') t--;
    
                left++;
            }
        }
    
        return (minlen == INT_MAX) ? -1 : minlen;
    }
};
