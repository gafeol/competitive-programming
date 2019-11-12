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

const int MAXN = 100345;
const int LOGN = 17;

int n, m, k;
int s[MAXN];

struct arv{
    int L, R;
    int mx, l, r, tot;
} zero;

arv tree[4*MAXN + MAXN*LOGN];
int cnt;
vector<pii> raiz;

int create(int L=-1, int R=-1, int mx=0, int l=0, int r=0, int tot=0){
    tree[cnt++] = {L, R, mx, l, r, tot};
    return cnt-1;
}

int create(arv o){
    tree[cnt++] = o;
    return cnt-1;
}

int build(int i, int j){
    int idx = create();
    tree[idx].tot = j - i + 1;
    if(i != j) {
        int m = (i + j)/2;
        tree[idx].L = build(i, m);
        tree[idx].R = build(m+1, j);
    }
    return idx;
}

arv join(arv ln, arv rn){
    arv aux;
    aux.l = max(ln.l, (ln.l == ln.tot ? ln.l + rn.l : 0));
    aux.r = max(rn.r, (rn.r == rn.tot ? rn.r + ln.r : 0));
    aux.mx = max(ln.mx, max(rn.mx, max(ln.r + rn.l, max(aux.l, aux.r))));
    return aux;
}

void upd(int idx, int i, int j, int x){
    arv &r = tree[idx];
    if(i == j){
        r.mx = r.l = r.r = 1;
        return ;
    }
    int m = (i + j)/2;
    if(x <= m){
        r.L = create(tree[r.L]);    
        upd(r.L, i, m, x);
    }
    else{
        r.R = create(tree[r.R]);
        upd(r.R, m+1, j, x);
    }

    arv aux = join(tree[r.L], tree[r.R]);
    r.l = aux.l;
    r.r = aux.r;
    r.mx = aux.mx;
}

arv qry(int idx, int i, int j, int l, int r){
    if(i > r || j < l) return zero;
    if(i >= l && j <= r)
        return tree[idx];
    int m = (i + j)/2;
    return join(qry(tree[idx].L, i, m, l, r),
            qry(tree[idx].R, m+1, j, l, r));
}

void add(int i, int val){   
    int nr = create(tree[raiz.back().fst]);
    raiz.pb({nr, val});
    upd(nr, 0, n-1, i);
}

int ind[MAXN];

int main (){
    zero = {0, 0, 0, 0, 0, 0};
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        ind[a] = a;
	}
    build(0, n-1);
    raiz.pb({0, 0});
    sort(ind, ind+n, [](int a, int b) { return s[a] > s[b]; });
    for(int a=0;a<n;a++){
        add(ind[a], s[ind[a]]);
        arv aux = qry(raiz.back().fst, 0, n-1, 0, n-1);
    }
    scanf("%d", &m);
    for(int a=0;a<m;a++){
        int l, r, w;
        scanf("%d %d %d", &l, &r, &w);
        l--;
        r--;
        int i = 0, j = raiz.size()-1;
        while(i < j){
            int m = (i + j)/2;
            if(qry(raiz[m].fst, 0, n-1, l, r).mx >= w)
                j = m;
            else
                i = m+1;
        }
        printf("%d\n", raiz[i].snd);
    }
}

