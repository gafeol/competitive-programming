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

const int MAXN = 1123456;
const ll INF = 400000000000LL;

int n, m, k;
int s[MAXN];


struct arv{
    ll bst;
    ll tot;
} tree[4*MAXN];

void upd(int idx, int i, int j, int l, ll x){
    if(i > l || j < l) return;
    if(i == j){
        tree[idx].bst += x;
        tree[idx].tot += x;
        return ;
    }
    int m = ((i+j)>>1);
    upd(idx*2, i, m, l, x);
    upd(idx*2+1, m+1, j, l, x);

    tree[idx].bst = max(tree[idx*2].bst, tree[idx*2].tot + tree[idx*2+1].bst);
    tree[idx].tot = tree[idx*2].tot + tree[idx*2+1].tot;
    tree[idx].bst = max(tree[idx].bst, tree[idx].tot);
}

void add(int i, ll x){
    upd(1, 0, MAXN-1, i, x);
}

int main (){
	scanf("%d%d%d", &n, &m, &k);
    vector<pii> Aaux, A;
	for(int a=0;a<n;a++){
        pii p;
        scanf("%d%d", &p.fst, &p.snd);
        Aaux.pb(p);
	}
    sort(Aaux.begin(), Aaux.end());
    for(pii x: Aaux){
        while(!A.empty() && A.back().snd >= x.snd)
            A.pop_back();
        if(!A.empty() && A.back().fst == x.fst) continue;
        A.push_back(x);
    }
    vector<pii> aux, B;
	for(int a=0;a<m;a++){
        pii p;
        scanf("%d%d", &p.fst, &p.snd);
        aux.pb(p);
	}
    sort(aux.begin(), aux.end());
    for(pii x: aux){
        while(!B.empty() && B.back().snd >= x.snd)
            B.pop_back();
        if(!B.empty() && B.back().fst == x.fst) continue;
        B.push_back(x);
    }
    int lst = 0, paid = 0;
    for(int i=0;i<B.size();i++){
        add(lst, paid-B[i].snd);        
        lst = B[i].fst;
        paid = B[i].snd;
    }  
    add(lst, -INF);

    vector<tuple<int, int, int> > s;
    for(int a=0;a<k;a++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        s.pb({u, v, w});
    }
    ll res = LLONG_MIN;
    sort(s.begin(), s.end());
    int i = 0;
    for(pii sw: A){
        while(i < k && get<0>(s[i]) < sw.fst){
            add(get<1>(s[i]), get<2>(s[i]));
            i++;
        }
        res = max(res, tree[1].bst -sw.snd);
    }
    printf("%lld\n", res);
}

