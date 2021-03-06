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

const int MAXN = 10, MAXN2 = 60;

int n, m, k;
int s[MAXN];
char M[MAXN][MAXN];

char ans[MAXN][MAXN];

int pai[MAXN2], sz[MAXN2];

//          R  U  L   D
int vi[] = {0, -1, 0, 1};
int vj[] = {1, 0, -1, 0};

//          LU  LD  RU RD
int xi[] = {-1,  1, -1, 1};
int xj[] = {-1,  -1, 1, 1};


bool valid(int i, int j){
    return (i >= 0 && j >= 0 && i < n+1 && j < n+1);
}

int raiz(int u){
    if(pai[u] == u) return u;
    return pai[u] = raiz(pai[u]);
}

int Raiz(int i, int j){
    return raiz(i*(n+1) + j);
}

bool join(int i, int j, int ii, int jj){
    int u = i*(n+1) + j;
    int v = ii*(n+1) + jj;
    u = raiz(u);
    v = raiz(v);

    if(sz[u] < sz[v])
        swap(u, v);
    pai[v] = u;
    sz[u] += sz[v];
}

void add_edge(int i, int j, int ii, int jj){
    if(!valid(i, j) || !valid(ii, jj)) return ;     
    int pi = min(i, ii);
    int pj = min(j, jj);
    if(i < ii && j < jj)
        ans[pi][pj] = '\\';
    else if(i < ii && j > jj)
        ans[pi][pj] = '/';
    else if(i > ii && j < jj)
        ans[pi][pj] = '/';
    else
        ans[pi][pj] = '\\';

    join(i, j, ii, jj);
}

bool border(int a, int b){
    return (a == 0 || b == 0 || a == n || b == n);
}

bool corner(int a, int b){
    return (border(a, 1) && border(1, b));
}

void heur(){
    for(int a=0;a<n+1;a++){
        for(int b=0;b<n+1;b++){
            if(M[a][b] == '0'){
                for(int d=0;d<4;d++){
                    int nxtd = (d + 1)%4;        
                    add_edge(a + vi[d], b + vj[d], a + vi[nxtd], b + vj[nxtd]);
                }
            }
            if(M[a][b] == '4' || (M[a][b] == '2' && border(a, b)) || (M[a][b] == '1' && corner(a, b))){
                for(int d=0;d<4;d++){
                    add_edge(a+xi[d], b+xj[d], a, b);
                }
            }
        }
    }
}

void step(){
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            if(Raiz(a, b) == Raiz(a+1, b+1))
                add_edge(a+1, b, a, b+1);
            else if(Raiz(a+1, b) == Raiz(a, b+1))
                add_edge(a, b, a+1, b+1);
        }
    }
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n+1;a++){
        for(int b=0;b<n+1;b++){
            scanf(" %c", &M[a][b]);
            pai[a*(n+1) + b] = a*(n+1)+b;
            sz[a*(n+1)+b] = 1;
        }
	}
    heur();
    int cnt = 100;
    while(cnt--) step();
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            printf("%c", ans[a][b]);
            if(!ans[a][b])
                printf(".");
        }
        puts("");
    }
}

