#include <bits/stdc++.h>
using namespace std;

using instance = vector<pair<int, int>>;
int m[20][20];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void print(instance& c) {
    printf("{\n");
    for (auto a: c) {
        printf("\t{%d, %d}\n", a.first, a.second);
    }
    printf("}\n");
}

void print_map(int h, int w) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("%3d", m[i][j]);
        }
        puts("");
    }
}

int main() {
    int n, w, h, l; scanf("%d %d %d %d", &n, &w, &h, &l);
    instance s(n);
    pair<int, int> goal;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c; scanf(" %c", &c);
            if (c == 'W')
                m[i][j] = -1;
            else
                m[i][j] = 0;
            if (c >= '1' && c <= '4')
                s[c - '1'] = {i, j};
            if (c == 'X')
                goal = {i, j};
        }
    }
    map<instance, int> height;
    queue<instance> q;
    height[s] = 0;
    q.push(s);
    while (q.size()) {
        instance u = q.front();
        for (int j = 0; j < n; j++) {
            m[u[j].first][u[j].second] = -1;
        }
        int he = height[u];
        q.pop();
        if (h == l) break;
        for (int i = 0; i < n; i++) {
            m[u[i].first][u[i].second] = 0;
            for (int d = 0; d < 4; d++) {
                instance v(n);
                copy(u.begin(), u.end(), v.begin());
                int x = v[i].first;
                int y = v[i].second;
                while (m[x][y] == 0 && x < h && x >= 0 && y < w && y >= 0) {
                    v[i] = {x, y};
                    x += dx[d];
                    y += dy[d];
                }
                if (v[0] == goal) {
                    printf("%d\n", he + 1);
                    return 0;
                }
                if (height.find(v) == height.end()) {
                    height[v] = he + 1;
                    q.push(v);
                }
            }
            m[u[i].first][u[i].second] = -1;
        }
        for (int j = 0; j < n; j++) {
            m[u[j].first][u[j].second] = 0;
        }
    }
    printf("NO SOLUTION\n");
    return 0;
}
