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
int s[MAXN];


struct arv{
    int mx;
    ll sum;
} tree[MAXN*4];

void build(int idx, int i, int j){
    if(i == j){
        tree[idx] = {s[i], s[i]};
        return ;
    }

    int m = (i + j)/2;
    build(idx*2, i, m);
    build(idx*2+1, m+1, j);
    
    tree[idx].mx = max(tree[idx*2].mx, tree[idx*2+1].mx);
    tree[idx].sum = tree[idx*2].sum + tree[idx*2+1].sum;
}

ll qry(int idx, int i, int j, int l, int r){
    if(i > r || j < l) return 0;

    if(i >= l && j <= r)
        return tree[idx].sum;
    
    int m = (i + j)/2;
    return qry(idx*2, i, m, l, r) + qry(idx*2+1, m+1, j, l, r);

}


void updm(int idx, int i, int j, int l, int r, int x){
    if(i > r || j < l) return ;
    if(tree[idx].mx < x) return ;
    if(i == j){
        tree[idx].mx = tree[idx].mx%x;
        tree[idx].sum = tree[idx].sum%x;
        return ;
    }
    int m = (i + j)/2;
    updm(idx*2, i, m, l, r, x);
    updm(idx*2+1, m+1, j, l, r, x);

    tree[idx].mx = max(tree[idx*2].mx, tree[idx*2+1].mx);
    tree[idx].sum = tree[idx*2].sum + tree[idx*2+1].sum;
}

void upd(int idx, int i, int j, int l, int x){
    if(i > l || j < l) return ;
    if(i == j){
        tree[idx].mx = x;
        tree[idx].sum =x;
        return ;
    }
    int m = (i + j)/2;
    upd(idx*2, i, m, l, x);
    upd(idx*2+1, m+1, j, l, x);

    tree[idx].mx = max(tree[idx*2].mx, tree[idx*2+1].mx);
    tree[idx].sum = tree[idx*2].sum + tree[idx*2+1].sum;
}


int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
	}
    build(1, 0, n-1);
    for(int a=0;a<m;a++){
        int t, l, r;
        scanf("%d%d%d", &t, &l, &r);
        l--;r--;
        if(t == 1){
            printf("%lld\n", qry(1, 0, n-1, l, r));
        }
        else if(t == 2){
            int x;
            scanf("%d", &x);
            updm(1, 0, n-1, l, r, x);
        }
        else{
            r++;
            upd(1, 0, n-1, l, r);
        }
    }

}

