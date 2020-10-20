#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 260;

int n, m, k;
int s[MAXN];

int M[MAXN][MAXN][2];

bool valid(int i, int j){
    return (i>=0 && j>=0 && i < n && j < m);
}

vector<tuple<int, int, int>> adj(int i, int j,int t){
    vector<tuple<int, int, int>> adj;

    auto add = [&](int i, int j, int t) {
        if(valid(i, j) && M[i][j][t] == 0)
            adj.emplace_back(i, j, t);
    };

    if((i+j)&1){
        // 0
        // 1
        add(i, j-1, 1);
        add(i, j+1, 0);
        int di = (t == 0 ? -1 : 1);
        add(i+di, j, 0);
        add(i+di, j, 1);
    }
    else{
        // 0 1
        add(i-1, j, 1);
        add(i+1, j, 0);
        int dj = (t == 0 ? -1 : 1);
        add(i, j+dj, 0);
        add(i, j+dj, 1);
    }
    return adj;
}

int id(int i, int j, int t){
    return i*m*2 + j*2 + t;
}

tuple<int, int, int> inv(int id){
    int t = id%2;
    id /= 2;
    int j = id%m;
    int i = id/m;
    return {i, j, t};
}

void reset(int id){
    for(int a=0;a<=id;a++){
    }
}

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &m);
        reset(id(n, m, 1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char c1, c2;
                scanf(" %c%c", &c1, &c2);
                M[i][j][0] = (c1=='1');
                M[i][j][1] = (c2=='1');
            }
        }
    }
}

