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

const int MAXN = 212345, MAXD = 200000;

int n, m, k;

struct arv{
    int mx, lz;
} tree[MAXN*4];

void unlaze(int idx, int i, int j){
    int aux = tree[idx].lz;
    tree[idx].lz = 0;
    if(i != j){
        tree[idx*2].mx += aux;
        tree[idx*2+1].mx += aux;
        tree[idx*2].lz += aux;
        tree[idx*2+1].lz += aux;
    }
}

void upd(int idx, int i, int j, int l, int r, int x){
    if(i > r || j < l) return ;
    unlaze(idx, i, j);
    if(i >= l && j <= r){
        tree[idx].mx += x;
        tree[idx].lz += x;
        return ;
    }
    int m = (i + j)/2;
    upd(idx*2, i, m, l, r, x);
    upd(idx*2+1, m+1, j, l, r, x);
    tree[idx].mx = max(tree[idx*2].mx, tree[idx*2+1].mx);
}

int main (){
    int alf1, alf2;
	scanf("%d%d%d.%d", &n, &k, &alf1, &alf2);
    int ialf = alf1*100 + alf2;
    vector<pii> s;
	for(int a=0;a<n;a++){
        int r;
        int w1, w2;
        scanf("%d %d.%d", &r, &w1, &w2);
        s.pb({w1*100+w2, r});
        s.pb({w1*100+w2+36000, r});
	}
    sort(s.begin(), s.end());
    int i = 0;     
    int ans = 0;
    for(int j=0;j<s.size();j++){
        while(s[j].fst - s[i].fst > ialf){
            upd(1, 0, MAXD, s[i].snd, s[i].snd + k, -1); 
            i++;
        }
        upd(1, 0, MAXD, s[j].snd, s[j].snd + k, 1);
        ans = max(ans, tree[1].mx);
    }
    printf("%d\n", ans);
}

