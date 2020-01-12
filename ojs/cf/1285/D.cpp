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

const int MAXN = 112345*30;

int n, m, k;

int tree[MAXN][2];
int tam[MAXN];
int sz;


int nxt(int u, int b){
    if(tree[u][b] == -1){
        tree[sz][0] = tree[sz][1] = -1;
        tree[u][b] = sz;
        sz++;
    }
    return tree[u][b];
}

void tadd(int u, int x, int h){
    tam[u]++;
    if(h == -1) return; 
    int b = ((x&(1<<h)) > 0); 
    tadd(nxt(u, b), x, h-1);
}

void add(int x){
    tadd(0, x, 29);
}

int szt(int u, int b){
    if(tree[u][b] == -1)
        return 0;
    return tam[tree[u][b]];
}

int qry(int u, int res, int h){
    if(h == -1)
        return res;
    if(szt(u, 0) > 0 && szt(u, 1) > 0){
        return min(qry(nxt(u, 0), res*2+1, h-1),
                qry(nxt(u, 1), res*2+1, h-1));
    }
    else if(szt(u, 0) == 0)
        return qry(nxt(u, 1), res*2, h-1);
    else
        return qry(nxt(u, 0), res*2, h-1);
}

int main (){
	scanf("%d", &n);
    sz = 1;
    tree[0][0] = tree[0][1] = -1;
	for(int a=0;a<n;a++){
        int x;
        scanf("%d", &x);
        add(x);
	}
    printf("%d\n", qry(0, 0, 29));
}

