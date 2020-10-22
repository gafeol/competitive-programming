#include <bits/stdc++.h>
using namespace std;

const int N = 512345;

struct data_info {
    int data, version, start;
    bool operator<(const data_info& o) const {
        return data < o.data;
    }
};

struct seg_tree {
    data_info seg[4*N];
    data_info lazy[4*N];

    seg_tree() {
        for (int i = 0; i < 4 * N; i++) {
            seg[i] = lazy[i] = {-1};
        }
    }

    void do_lazy(int i, int l, int r) {
        if (lazy[i].data != -1) {
            seg[i] = lazy[i];
            if (l != r) {
                lazy[2 * i + 1] = lazy[i];
                lazy[2 * i + 2] = lazy[i];
            }
            lazy[i] = {-1};
        }
    }

    void update(int ql, int qr, data_info v, int l = 0, int r = N - 1, int i = 0) {
        do_lazy(i, l, r);
        if (qr < l || r < ql)
            return;
        if (ql <= l && r <= qr) {
            lazy[i] = v;
            do_lazy(i, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(ql, qr, v, l, mid, 2 * i + 1);
        update(ql, qr, v, mid + 1, r, 2 * i + 2);
        seg[i] = max(seg[2 * i + 1], seg[2 * i + 2]);
    }

    data_info query(int p, int l = 0, int r = N - 1, int i = 0) {
        do_lazy(i, l, r);
        if (p < l || r < p)
            return {-1};
        if (p <= l && r <= p)
            return seg[i];
        int mid = (l + r) / 2;
        return max(query(p, l, mid, 2 * i + 1), query(p, mid + 1, r, 2 * i + 2));
    }
} cache;

struct BIT {
    vector<int> b;
    BIT(int size) {
        b.resize(size + 10);
    }
    void update(int p, int val) {
        for(p++; p < b.size(); p += p & -p)
            b[p] += val;
    }
    int get_sum(int p) {
        int sum = 0;
        for(p++; p != 0; p -= p & -p)
            sum += b[p];
        return sum;
    }
};
vector<BIT> db;

vector<int> d[N];
int v[N], sz[N], resp[N];

vector<pair<int, int>> up[N];

struct query_info {
    int version, position, index;
    bool operator<(const query_info& o) const {
        return version < o.version;
    }
};
vector<query_info> qinfo[N];

int main() {
    int n, m, q; scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < m; i++) {
        scanf("%d", &sz[i]);
        d[i].resize(sz[i]);
        db.push_back(BIT(sz[i]));
        for (int j = 0; j < sz[i]; j++) {
            scanf("%d", &d[i][j]);
        }
    }
    int qi = 0;
    for (int i = 0; i < q; i++) {
        int type; scanf("%d", &type);
        if (type == 1) {
            int d, p;
            scanf("%d %d", &d, &p);
            d--;
            cache.update(p, p + sz[d] - 1, {d, v[d], p});
        } else if (type == 2) {
            int p;
            scanf("%d", &p);
            data_info r = cache.query(p);
            if (r.data != -1) {
                qinfo[r.data].push_back({r.version, p - r.start, qi});
            }
            qi++;
        } else if (type == 3) {
            int d, l, r;
            scanf("%d %d %d", &d, &l, &r);
            d--;
            up[d].push_back({l, r});
            v[d]++;
        }
    }
    for (int i = 0; i < m; i++) {
        v[i] = 0;
        int last = 0;
        sort(qinfo[i].begin(), qinfo[i].end());
        up[i].push_back({1, 1});
        for (auto u: up[i]) {
            while (last < qinfo[i].size() && qinfo[i][last].version == v[i]) {
                int pos = qinfo[i][last].position;
                resp[qinfo[i][last].index] = (d[i][pos] + db[i].get_sum(pos) - db[i].get_sum(pos - 1)) % 256;
                last++;
            }
            db[i].update(u.first - 1, 1);
            db[i].update(u.second, -1);
            v[i]++;
        }
    }
    for (int i = 0; i < qi; i++) {
        printf("%d\n", resp[i]);
    }
}

