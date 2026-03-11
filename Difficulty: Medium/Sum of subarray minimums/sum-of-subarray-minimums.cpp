class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<pair<int, int>> s;

        for (int i = 0; i < n; ++i) {
            int count = 1;
            while (!s.empty() && s.top().first > arr[i]) {
                count += s.top().second;
                s.pop();
            }
            left[i] = count;
            s.push({arr[i], count});
        }

        while (!s.empty()) s.pop();

        for (int i = n - 1; i >= 0; --i) {
            int count = 1;
            while (!s.empty() && s.top().first >= arr[i]) {
                count += s.top().second;
                s.pop();
            }
            right[i] = count;
            s.push({arr[i], count});
        }

        long long result = 0;
        int MOD = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            result = (result + (long long)arr[i] * left[i] * right[i]) % MOD;
        }
        return result;
    }
};