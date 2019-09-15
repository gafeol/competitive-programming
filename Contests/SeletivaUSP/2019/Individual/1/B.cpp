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

const int MAXN = 212345;

int n, m, k;
pii s[MAXN];

bool mrk[MAXN];

int sz[MAXN], p[MAXN];
int ncomp;

int raiz(int u){
    if(p[u] == u) return u;
    return p[u] = raiz(p[u]);
}


void join(int i, int j){
    i = raiz(i);
    j = raiz(j);

    if(i == j) return ;
    ncomp--;

    if(sz[i] < sz[j])
        swap(i, j);
    
    sz[i] += sz[j];
    p[j] = i;
}
int main (){
	scanf("%d%d", &n, &m);
    ncomp = n;
    for(int a=0;a<=n;a++){
        sz[a] = 1;
        p[a] = a;
    }
	for(int a=0;a<m;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        s[a] = pii(i, j);
        mrk[a] = 0;
	}
    int q;
    scanf("%d", &q); 
    vector<int> rmv;
    for(int a=0;a<q;a++){
        int x;
        scanf("%d", &x);
        x--;
        rmv.push_back(x);
        mrk[x] = 1;
    }
    for(int a=0;a<m;a++){
        if(mrk[a]) continue;
        join(s[a].fst, s[a].snd);
    }
    stack<int> ans;
    for(int i=rmv.size()-1;i>=0;i--){
        ans.push(ncomp);
        join(s[rmv[i]].fst, s[rmv[i]].snd);
    }
    while(!ans.empty()){
        printf("%d ", ans.top());
        ans.pop();
    }
}

