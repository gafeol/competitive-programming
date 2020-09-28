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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 53;

int n, m, k;
int s[MAXN];

int M[MAXN][MAXN];
int MM[MAXN][MAXN];

inline int ask(int i, int j, int ii, int jj){
    printf("? %d %d %d %d\n", i+1, j+1, ii+1, jj+1);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    if(x == -1) exit(0);
    return x;
}

bool valid(int i, int j){
    return (i >= 0 && j >= 0 && i < n && j < n);
}

int vi[] = {0, 1, 2};
int vj[] = {2, 1, 0};

void go(int i, int j){
    for(int d=0;d<4;d++){
        int ii = i + vi[d];
        int jj = j + vj[d];
        if(valid(ii, jj) && M[ii][jj] == -1){
            int x = ask(i, j, ii, jj); 
            M[ii][jj] = 1^x^M[i][j];
            go(ii, jj);
        }
    }
}

int main (){
	scanf("%d", &n);
    memset(M, -1, sizeof(M));
    M[0][0] = 1;
    M[n-1][n-1] = 0;
    go(0, 0);
    M[0][1] = 0;
    go(0, 1);
    int x = ask(1, 0, 2, 1);
    M[1][0] = 1^x^M[2][1];
    go(1, 0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            MM[i][j] = M[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=!(i&1);j<n;j+=2){
            MM[i][j] ^= 1;

        }
    }
}

