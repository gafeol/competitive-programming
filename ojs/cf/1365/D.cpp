#include <bits/stdc++.h>
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

const int MAXN = 55;

int n, m, k;
int s[MAXN];
char M[MAXN][MAXN];
int vis[MAXN][MAXN];

bool valid(int i, int j){
    return (i>=0 && j >= 0 && i < n && j < m); 
}


void w(int i, int j){
    if(valid(i, j) && M[i][j] == '.')
        M[i][j] = '#';
}
int vi[] = {0, 0, -1, 1};
int vj[] = {1, -1, 0, 0};

void go(int i,  int j){
    vis[i][j]  = true;
    for(int d=0;d<4;d++){
        int ii = vi[d] + i, jj = vj[d] + j;
        if(valid(ii, jj) && M[ii][jj] != '#' && !vis[ii][jj])
            go(ii, jj);
    }
}

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &m);
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                vis[a][b] = 0;
                scanf(" %c", &M[a][b]);
            }
        }
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                if(M[a][b] == 'B'){
                    for(int d=0;d<4;d++){
                        int aa = a+ vi[d], bb = b + vj[d];
                        w(aa, bb);
                    }
                }
            }
        }
        if(M[n-1][m-1] != '#')
            go(n-1, m-1);
        bool ok = true;
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                if(M[a][b] == 'B' && vis[a][b])
                    ok = false;
                if(M[a][b] == 'G' && !vis[a][b])
                    ok = false;
            }
        }
        if(ok)
            puts("Yes");
        else
            puts("No");
    }
}

