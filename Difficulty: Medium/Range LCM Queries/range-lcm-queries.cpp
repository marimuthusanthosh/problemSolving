class Solution {
  public:

    vector<long long> tree;
    int n;

    // ─── GCD ──────────────────────────────────────────────────
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    // ─── LCM ──────────────────────────────────────────────────
    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    // ─── BUILD ────────────────────────────────────────────────
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2*node,   start, mid);
            build(arr, 2*node+1, mid+1, end);
            tree[node] = lcm(tree[2*node], tree[2*node+1]);
        }
    }

    // ─── UPDATE ───────────────────────────────────────────────
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(2*node,   start, mid,   idx, val);
            else
                update(2*node+1, mid+1, end,   idx, val);
            tree[node] = lcm(tree[2*node], tree[2*node+1]);
        }
    }

    // ─── QUERY ────────────────────────────────────────────────
    long long query(int node, int start, int end, int L, int R) {
        if (R < start || end < L)
            return 1;                                        // out of range
        if (L <= start && end <= R)
            return tree[node];                              // fully inside
        int mid = (start + end) / 2;
        long long left  = query(2*node,   start, mid,   L, R);
        long long right = query(2*node+1, mid+1, end,   L, R);
        return lcm(left, right);
    }

    // ─── MAIN ─────────────────────────────────────────────────
    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries) {
        n = arr.size();
        tree.assign(4 * n, 1);
        build(arr, 1, 0, n - 1);

        vector<long long> result;

        for (auto& q : queries) {
            if (q[0] == 1) {
                update(1, 0, n-1, q[1], q[2]);             // update index
            } else {
                result.push_back(query(1, 0, n-1, q[1], q[2])); // range lcm
            }
        }
        return result;
    }
};