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

const int MAXN = 100005;

struct arv{
    int lz;
    int mx, qmn;
} tree[32][MAXN*4];

int n, m, k;
int s[MAXN];


inline bool lucky(int x){
    while(x > 0) {
        if(x%10 != 4 && x%10 != 7) return false;
        x/= 10;
    }
    return true;
}

inline void unlaze(int idt, int idx, int i, int j){
    int aux = tree[idt][idx].lz;
    tree[idt][idx].lz = 0;
    if(aux != 0 && i != j){
        arv &L  = tree[idt][idx*2];
        if(L.mx > 0){
            L.lz += aux;
            L.mx += aux;
            L.qmn = 0;
        }

        arv &R = tree[idt][idx*2+1];
        if(R.mx > 0){
            R.lz += aux;
            R.mx += aux;
            R.qmn = 0;
        }
    }
}

vector<int> lim;
void upd(int t, int idx, int i, int j, int l, int x){
    if(i > l || j < l) return;
    unlaze(t, idx, i, j);
    if(i == j){
        tree[t][idx].mx = x;
        tree[t][idx].qmn = (x == lim[t]);
        return ;
    }
    int m = (i + j)/2;
    upd(t, idx*2, i, m, l, x);
    upd(t, idx*2+1, m+1, j, l, x);
    tree[t][idx].mx = max(tree[t][idx*2].mx, tree[t][idx*2+1].mx);
    tree[t][idx].qmn = tree[t][idx*2].qmn + tree[t][idx*2+1].qmn;
}

void upd(int t, int idx, int i, int j, int l, int r, int x){
    if(i > r || j < l || tree[t][idx].mx == 0) return ; 
    unlaze(t, idx, i, j);
    if(i >= l && j <= r){
        tree[t][idx].mx += x;
        tree[t][idx].qmn = 0;
        tree[t][idx].lz += x;
        return ;
    }
    int m = (i + j)/2;
    upd(t, idx*2, i, m, l, r, x);
    upd(t, idx*2+1, m+1, j, l, r, x);
    tree[t][idx].mx = max(tree[t][idx*2].mx, tree[t][idx*2+1].mx);
    tree[t][idx].qmn = tree[t][idx*2].qmn + tree[t][idx*2+1].qmn;
}

int qry(int t, int idx, int i, int j, int l, int r){
    if(i > r || j < l || tree[t][idx].qmn == 0) return 0;
    unlaze(t, idx, i, j);
    if(i >= l && j <= r)
        return tree[t][idx].qmn;
    int m = (i + j)/2;
    return qry(t, idx*2, i, m, l, r) + qry(t, idx*2+1, m+1, j, l, r);
}

int rmvmx(int t, int idx, int i, int j){
    unlaze(t, idx, i, j);
    if(i == j){
        tree[t][idx].mx = 0;
        tree[t][idx].qmn = 0;
        tree[t][idx].lz = 0;
        return i;
    }
    int m = (i + j)/2;
    int ans;
    if(tree[t][idx*2].mx == tree[t][idx].mx)
        ans = rmvmx(t, idx*2, i, m);
    else
        ans = rmvmx(t, idx*2+1, m+1, j);

    tree[t][idx].mx = max(tree[t][idx*2].mx, tree[t][idx*2+1].mx);
    tree[t][idx].qmn = tree[t][idx*2].qmn + tree[t][idx*2+1].qmn;
    return ans;
}


int indt[MAXN];
int main (){
    lim.pb(0);
    for(int a=1;a<=10000;a++){
        if(lucky(a)){
            lim.pb(a);
        }
        indt[a] = lim.size()-1;
    }
    lim.pb(INT_MAX);
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        int idt = indt[s[a]];
        upd(idt, 1, 0, n-1, a, s[a]);
	}

    for(int a=0;a<m;a++){
        char t[MAXN];
        int i, j;
        scanf(" %s %d %d", t, &i, &j);
        i--;j--;
        if(t[0] == 'c'){
            int ans = 0;
            for(int idt=1;idt<lim.size()-1;idt++){
                ans += qry(idt, 1, 0, n-1, i, j);
            }
            printf("%d\n", ans);
        }
        else{
            int x;
            scanf("%d", &x);
            for(int idt=lim.size()-2;idt>=0;idt--){
                upd(idt, 1, 0, n-1, i, j, x);
                while(tree[idt][1].mx >= lim[idt+1]){
                    int val = tree[idt][1].mx;
                    int i = rmvmx(idt, 1, 0, n-1);
                    int nt = indt[val];
                    upd(nt, 1, 0, n-1, i, val);
                }
            }
        }
    }
}

