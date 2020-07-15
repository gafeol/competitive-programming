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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

unordered_map<int, unordered_map<int, int>> sz;
unordered_map<int, unordered_map<int, int>> pai;
int ans;

int raiz(int t, int i){
    if(pai[t][i] == i) return i;
    return pai[t][i] = raiz(t, pai[t][i]);
}

bool join(int t, int i, int j){
    i = raiz(t, i);
    j = raiz(t, j);
    if(i == j) return false;
    if(sz[t][i] < sz[t][j])
        swap(i, j);
    pai[t][j] = i;
    sz[t][i] += sz[t][j];
    return true;
}

void add(int t, int x){
    ans++;
    //printf("Add %d %d\nans++ = %d\n", t, x, ans);
    pai[t][x] = x;
    sz[t][x] = 1;
    
    if(pai[t].find(x-1) != pai[t].end()){
        ans -= join(t, x-1, x);
        //printf("join t %d %d %d ans %d\n", t, x-1, x, ans);
    }
    if(pai[t].find(x+1) != pai[t].end()){
        ans -= join(t, x+1, x);
        //printf("join t %d %d %d ans %d\n", t, x+1, x, ans);
    }
}


int on[MAXN];

int get(int u){
    if(on[u] == u) return u;
    return on[u] = get(on[u]);
}

int main (){
    ans = 0;
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        int x;
        scanf("%d", &x);
        add(x, a+1);
	}
    for(int a=1;a<=m;a++){
        on[a] = a;
    }
    printf("%d\n", ans-1);
    for(int a=1;a<m;a++){
        int l, r;
        scanf("%d%d", &l, &r);
        //printf("antes eh l eh %d r eh %d\n", l, r);
        l = get(l);
        r = get(r);
        //printf("l eh %d r eh %d\n", l, r);

        if(sz[l].size() < sz[r].size())
            swap(l, r);
        on[r] = l;
        // join r to l
        for(auto it: pai[r]){
            int u = it.fst;
            int p = it.snd;
            if(p == u){
                ans--;
                //printf("Ans-- pq p %d == u %d\n", u, p);
            }
            add(l, u);
        }
        printf("%d\n", ans-1);
    }
}

