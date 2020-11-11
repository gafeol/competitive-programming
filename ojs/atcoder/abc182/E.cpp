#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define eb emplace_back
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

const int MAXN = 1510;

int n, m, k;
int h, w;
int M[MAXN][MAXN];
int mrk[4][MAXN][MAXN];

int vi[] = {1, 0, -1, 0};
int vj[] = {0, -1, 0, 1};

bool valid(int i, int j){
    return (i >= 0 && j >= 0 && i < h && j < w);
}

void go(int d, int i, int j){
    if(mrk[d][i][j]) return ;
    mrk[d][i][j] = 1;
    M[i][j] = 1;
    int ii = i + vi[d], jj = j + vj[d];
    if(valid(ii, jj) && M[ii][jj] != 2)
        go(d, ii, jj);

}

int main (){
	scanf("%d%d%d%d", &h, &w, &n, &m);
    vector<pii> l(n);
	for(int a=0;a<n;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        i--;j--;
        l[a] = {i, j};
        M[i][j] = 1;
	}
    for(int a=0;a<m;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        i--;j--;
        M[i][j] = 2;
    }
    for(int a=0;a<n;a++){
        for(int d=0;d<4;d++){
            go(d, l[a].fst, l[a].snd);
        }
    }
    int ans = 0;
    for(int a=0;a<h;a++){
        for(int b=0;b<w;b++){
            ans += (M[a][b] == 1);
        }
    }
    printf("%d\n", ans);
    return 0;

}

