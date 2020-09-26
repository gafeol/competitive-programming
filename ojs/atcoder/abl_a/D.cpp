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

const int MAXN = 300005;

int tree[MAXN*4];

void upd(int idx, int i, int j, int l, int x){
    if(i > l || j < l) return;
    if(i == j){
        tree[idx] = x;
        return ;
    }
    int m = (i+j)/2;
    upd(idx*2, i,  m, l, x);
    upd(idx*2+1, m+1, j, l, x);
    tree[idx] = max(tree[idx*2], tree[idx*2+1]);
}

int qry(int idx, int i, int j,int l, int r){
    if(i > r || j < l) return 0;
    if(i >= l && j <= r)
        return tree[idx];
    int m = (i+j)/2;
    return max(qry(idx*2, i, m, l, r),
                qry(idx*2+1, m+1, j, l, r));
}

int n, m, k;
int s[MAXN];

int main (){
	scanf("%d%d", &n, &k);
    int ans = 0;
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        int val = 1 + qry(1, 0, MAXN-1,  max(0, s[a]-k), min(MAXN-1, s[a]+k));
        ans = max(ans, val);
        //printf("s[a] %d val %d\n", s[a], val);
        upd(1, 0, MAXN-1, s[a], val);
	}
    printf("%d\n", ans);
}

