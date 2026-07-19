class Solution {
  public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();
        if (n == 0) return vector<bool>(queries.size(), false);
    
        vector<int> end_inc(n);
        end_inc[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            if (arr[i] <= arr[i + 1]) {
                end_inc[i] = end_inc[i + 1];
            } else {
                end_inc[i] = i;
            }
        }
    
        vector<int> start_dec(n);
        start_dec[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (arr[i - 1] >= arr[i]) {
                start_dec[i] = start_dec[i - 1];
            } else {
                start_dec[i] = i;
            }
        }
    
        vector<bool> result;
        result.reserve(queries.size());
    
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            int peak_end = end_inc[l];
            int valley_start = start_dec[r];
            result.push_back(peak_end >= valley_start);
        }
    
        return result;
    }
};