class Solution {
  public:
    int findMax(int n) {
        // Convert to string for easy manipulation
        string s = to_string(n);
        int len = s.length();

        // Start with n itself
        int bestNum = n;
        int bestSum = 0;
        for (char c : s) bestSum += (c - '0');

        // Generate all candidates
        // For each position i:
        // - Keep prefix same as n
        // - Reduce digit at i by 1
        // - Make all digits after i as 9
        for (int i = 0; i < len; i++) {
            if (s[i] == '0') continue;
            // Build candidate
            string cand = s;
            cand[i] = (char)(cand[i] - 1);
            for (int j = i + 1; j < len; j++) {
                cand[j] = '9';
            }

            // Remove leading zeros
            int num = stoi(cand);
            
            // Calculate digit sum
            int sum = 0;
            int temp = num;
            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }

            // Update best
            if (sum > bestSum || (sum == bestSum && num > bestNum)) {
                bestSum = sum;
                bestNum = num;
            }
        }

        return bestNum;
    }
};
