class Solution {
    static long long lcm(long long a, long long b) {
        return (a / __gcd(a, b)) * b;
    }

    vector<long long> segTree;
    int n;

    void build(int node, int start, int end, vector<int>& arr) {
        if (start == end) {
            segTree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;

        build(2 * node, start, mid, arr);
        build(2 * node + 1, mid + 1, end, arr);

        segTree[node] = lcm(segTree[2 * node], segTree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            segTree[node] = val;
            return;
        }

        int mid = (start + end) / 2;

        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);

        segTree[node] = lcm(segTree[2 * node], segTree[2 * node + 1]);
    }

    long long query(int node, int start, int end, int l, int r) {
        // No overlap
        if (r < start || end < l)
            return 1;

        // Complete overlap
        if (l <= start && end <= r)
            return segTree[node];

        int mid = (start + end) / 2;

        long long left = query(2 * node, start, mid, l, r);
        long long right = query(2 * node + 1, mid + 1, end, l, r);

        return lcm(left, right);
    }

public:
    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries) {

        n = arr.size();
        segTree.resize(4 * n);

        build(1, 0, n - 1, arr);

        vector<long long> ans;

        for (auto &q : queries) {

            // Update Query
            if (q[0] == 1) {
                int idx = q[1];
                int val = q[2];

                update(1, 0, n - 1, idx, val);
            }

            // Range LCM Query
            else {
                int l = q[1];
                int r = q[2];

                ans.push_back(query(1, 0, n - 1, l, r));
            }
        }

        return ans;
    }
};