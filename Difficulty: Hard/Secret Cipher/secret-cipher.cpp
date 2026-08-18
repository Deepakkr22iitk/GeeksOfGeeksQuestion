class Solution {
  public:
    string compress(string &s) {
        int n = s.length();
        if (n == 0) return "";

        // Build the Z-array for string s
        // Z[i] stores the length of the longest common prefix of s and s[i...n-1]
        vector<int> Z(n, 0);
        int L = 0, R = 0;
        for (int i = 1; i < n; i++) {
            if (i <= R) {
                Z[i] = min(R - i + 1, Z[i - L]);
            }
            while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
                Z[i]++;
            }
            if (i + Z[i] - 1 > R) {
                L = i;
                R = i + Z[i] - 1;
            }
        }

        string ans = "";
        int i = n - 1;

        // Greedily compress from right to left to ensure maximum compression 
        // and lexicographically smallest result.
        while (i >= 0) {
            // If the current prefix length (i + 1) is even, check if it can be halved
            if (i % 2 == 1) { 
                int k = (i + 1) / 2;
                // If the first half equals the second half, we can replace the second half with '*'
                if (Z[k] >= k) {
                    ans += '*';
                    i = k - 1; // Jump to the end of the first half
                    continue;
                }
            }

            // If it cannot be halved at this length, retain the character and move left
            ans += s[i];
            i--;
        }

        // The answer string was built backwards, so reverse it before returning
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
