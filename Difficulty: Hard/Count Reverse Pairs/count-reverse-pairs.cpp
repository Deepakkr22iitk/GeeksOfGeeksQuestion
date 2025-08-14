class Solution {
  public:
    int mergeCount(vector<pair<long long,int>>& v, int l, int r) {
        if (l >= r) return 0;
        int m = (l + r) / 2;
        int cnt = mergeCount(v, l, m) + mergeCount(v, m + 1, r);

        // Count reverse pairs between left and right halves
        int j = m + 1;
        for (int i = l; i <= m; ++i) {
            while (j <= r && v[i].first > 2LL * v[j].first) j++;
            cnt += (j - (m + 1));
        }

        // Merge step (by value)
        vector<pair<long long,int>> temp;
        temp.reserve(r - l + 1);
        int i = l;
        j = m + 1;
        while (i <= m && j <= r) {
            if (v[i].first <= v[j].first) temp.push_back(v[i++]);
            else temp.push_back(v[j++]);
        }
        while (i <= m) temp.push_back(v[i++]);
        while (j <= r) temp.push_back(v[j++]);

        for (int k = 0; k < (int)temp.size(); ++k) v[l + k] = temp[k];

        return cnt;
    }

    int countRevPairs(vector<int> &arr) {
        int n = arr.size();
        vector<pair<long long,int>> v(n);
        for (int i = 0; i < n; i++) v[i] = {arr[i], i};
        return mergeCount(v, 0, n - 1);
    }
};