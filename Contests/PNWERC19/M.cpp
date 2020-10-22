#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
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

const int MAXN = 2123;

int n, m, k;
int s[MAXN];
char w[MAXN][MAXN];

int M[MAXN][MAXN];

pii p[MAXN][MAXN];
int sz[MAXN][MAXN];
int ncomp;

int vi[] = {0, 0, 1, -1};
int vj[] = {1, -1, 0, 0};

bool valid(int i, int j){
    return (i >= 0 && j >= 0 && i < n && j < m);
}

pii raiz(int i, int j){
    if(p[i][j] == make_pair(i, j))
        return {i, j};
    return p[i][j] = raiz(p[i][j].fst, p[i][j].snd);
}

void join(int i, int j, int ii, int jj){
    tie(i, j) = raiz(i, j);
    tie(ii, jj) = raiz(ii, jj);
    if(mp(i, j) == mp(ii, jj))
        return ;
    ncomp--;
    if(sz[i][j] < sz[ii][jj]){
        swap(i, ii);
        swap(j, jj);
    }
    p[ii][jj] = mp(i, j);
    sz[i][j] += sz[ii][jj];
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            scanf(" %c", &w[a][b]);
            int i = a*2;
            int j = b*2;
            if(w[a][b] == '\\'){
                M[i][j] = M[i+1][j+1] = 1; 
            }
            else if(w[a][b] == '/'){
                M[i][j+1] = M[i+1][j] = 1;
            }
        }
	}
    n *= 2;
    m *= 2;
    for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            printf("%d", M[a][b]);
            ncomp += (M[a][b] == 0);
            p[a][b] = {a, b};
            sz[a][b] = 1;
        }
        puts("");
    }
    ncomp++;
    p[n][m] = {n, m};
    sz[n][m] = 1;
    for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            if(M[a][b] == 1) continue;
            for(int d=0;d<4;d++){
                int na = a + vi[d], nb = b + vj[d];
                if(!valid(na, nb))
                    join(n, m, a, b);
                else if(M[na][nb] == 0)
                    join(a, b, na, nb);
            }
        }
    }
    printf("%d\n", ncomp-1);
    return 0;
}

