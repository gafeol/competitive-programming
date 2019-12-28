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
ll s[MAXN], pos[MAXN];
ll inv[MAXN];

int bit[MAXN];

ll bqry(int x){
    x += 2;
    ll ans = 0;
    while(x < MAXN){
        ans += bit[x];
        x += (x&-x);
    }
    return ans;
}

void bupd(int x){
    int ox = x;
    x += 2;
    while(x > 0){
        bit[x]++;
        x -= (x&-x);
    }
}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define GNU __gnu_pbds

namespace GNU { typedef tree<int, null_type, less<int>, rb_tree_tag,
	tree_order_statistics_node_update> ordered_set; }
using GNU::ordered_set;
// null_type pode mudar pra virar map
// multiset e multimap nao tem suporte aqui, tem que sair usando pair pelo jeito
// less eh o comparador

ordered_set q;

// s.insert(int) s.erase(iterator ou int)
// end(s) == s.find_by_order(int) -> s nao contem int
// find_by_order retorna o iterator pro kth maior elemento (comecando do 0)
// 	(int) *s.find_by_order(int)
// order_of_key retorna o numero de elementos no set estritamente menor que int
// 	(int) s.order_of_key(int)

ll tree[4*MAXN];

void upd(int idx, int i, int j, int l, ll x){
    if(l < i || l > j) return ;
    if(i == j){
        tree[idx] = x;
        return ;
    }
    int m = (i + j)/2;
    upd(idx*2, i, m, l, x);
    upd(idx*2+1, m+1, j, l, x);
    tree[idx] = tree[idx*2] + tree[idx*2+1];
}

ll qry(int idx, int i, int j, int l, int r){
    if(j < i) return 0;
    if(l > j || r < i) return 0;
    if(i >= l && j <= r)
        return tree[idx];
    int m = (i + j)/2;
    return qry(idx*2, i, m, l, r) + qry(idx*2+1, m+1, j, l, r);
}

ll pa(ll i, ll j){
    if(i > j) return 0;
    assert(i >= 0);
    assert(j < n);
    ll n = (j - i+1ll);
    return ((i+j)*n)/2ll;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        pos[s[a]] = a;
	}
    int med[MAXN];
    for(int a=1;a<=n;a++){
        inv[a] = inv[a-1] + bqry(pos[a]);        
        bupd(pos[a]);
        q.insert(pos[a]);
        med[a] = *q.find_by_order(a/2);
        upd(1, 0, n-1, pos[a], pos[a]);
        int nl = a/2;
        ll suml = pa(med[a] - nl, med[a]-1);
        int nr = a - nl;
        ll sumr = pa(med[a], med[a]+nr-1);
        ll dsum = qry(1, 0, n-1, med[a], n-1) - sumr + suml - qry(1, 0, n-1, 0, med[a]-1); 
        //printf("qry %d %d: %lld  -  sumr %lld + suml %lld - qry %d %d: %lld\n", med[a], n-1, qry(1, 0, n-1, med[a], n-1),  sumr , suml , 0, med[a]-1, qry(1, 0, n-1, 0, med[a]-1));
        //printf("dsum %lld inv %lld\n", dsum, inv[a]);
        printf("%lld ", dsum + inv[a]);
    }
    puts("");
}
