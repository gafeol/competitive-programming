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

const int MAXN = 2123;

int n, m, k;
int s[MAXN];

char M[MAXN][MAXN];
int mrk[MAXN][MAXN];


int vi[] = {0, 1, 0, -1};
int vj[] = {1, 0, -1, 0};

bool valid(int i, int j){
    return (i >= 0 && j>= 0 && i < n && j < m && M[i][j] == '#');
}

void go(int i, int j){
    mrk[i][j] = 1;

    for(int d=0;d<4;d++){
        int ii = i + vi[d];
        int jj = j + vj[d];
        if(valid(ii, jj) && !mrk[ii][jj])
            go(ii, jj);
    }
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            scanf(" %c", &M[a][b]);
        }
	}
    bool ok = true;
    int cntl = 0;
    for(int a=0;a<n;a++){
        int st = 0;
        for(int b=0;b<m;b++){
            if(st == 0){
                if(M[a][b] == '#')
                    st++;
            }
            else if(st == 1){
                if(M[a][b] == '.')
                    st++;
            }
            else {
                if(M[a][b] == '#')
                    ok = false;
            }
        }
        cntl += (st == 0);
    }
    int cntc = 0;
    for(int b=0;b<m;b++){
        int st = 0;
        for(int a=0;a<n;a++){
            if(st == 0){
                if(M[a][b] == '#')
                    st++;
            }
            else if(st == 1){
                if(M[a][b] == '.')
                    st++;
            }
            else {
                if(M[a][b] == '#')
                    ok = false;
            }
        }
        cntc += (st == 0);
    }

    if((cntl == 0 && cntc > 0) || (cntl > 0 && cntc == 0))
        ok = false;

    if(!ok){
        puts("-1");
        return 0;
    }

    int ans = 0;
    for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            if(M[a][b] == '#' && !mrk[a][b]){
                ans++;
                go(a, b);
            }
        }
    }
    printf("%d\n", ans);
}
