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

const int MAXX = 1e9+1;

// Min val dynamic segtree
struct arv{
    ll sum;
    arv *L, *R;
    arv() : sum(0), L(NULL), R(NULL) {}
    arv* left() { // create if unexistent
        if(L == NULL){
            L = new arv();
        }
        return L;
    }
    arv* right() { // create if unexistent
        if(R == NULL)
            R = new arv();
        return R;
    }
};

ll val(arv* u){
    if(u == NULL)
        return 0;
    return u->sum;
}

arv* root;

void upd(arv* u, int i, int j, int l, ll x){
    if(i == j){
        u->sum += x;
        return ;
    }
    int m = (i+j)/2;
    if(l <= m)
        upd(u->left(), i, m, l, x);
    else
        upd(u->right(), m+1, j, l, x);
    u->sum = val(u->L) + val(u->R);
}

ll qry(arv *u, int i, int j, int l, int r){
    if(u == NULL || l > j || r < i) 
        return 0;
    if(i >= l && j <= r)
        return u->sum; 
    int m = (i + j)/2;
    return (qry(u->L, i, m, l, r) + 
                qry(u->R, m+1, j, l, r));
}

int n, m, k;

multiset<ll> ms;

void add(int x){
    upd(root, 1, MAXX, x, x);
    ms.insert(x);
}

void rmv(int x){
    upd(root, 1, MAXX, x, -x);
    ms.erase(ms.find(x));
}

int qry(){
    int fat = (!ms.empty());
    auto it = ms.begin();
    ll sum = (ms.empty() ? 0 : *ms.begin());
    multiset<ll>::iterator nxt;
    while((nxt = ms.upper_bound(2ll*sum)) != ms.end()){
        sum = qry(root, 1, MAXX, 1, *nxt-1);
        if(*nxt > 2ll*sum)
            fat++;
        sum += *nxt;
    }
    return ms.size() - fat;
}

int main (){
	scanf("%d", &n);
    root = new arv();
	for(int a=0;a<n;a++){
        char o;
        int x;
        scanf(" %c %d", &o, &x);
        if(o == '+')
            add(x);
        else
            rmv(x);
        printf("%d\n", qry());
	}
}

