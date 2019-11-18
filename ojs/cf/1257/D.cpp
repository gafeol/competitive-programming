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

int bst[MAXN];

int tree[MAXN*4];

void build(int idx, int i, int j){
    if(i == j){
        tree[idx] = s[i];
        return ;
    }
    int m = (i + j)/2;
    build(idx*2, i, m);
    build(idx*2+1, m+1, j);
    tree[idx] = max(tree[idx*2], tree[idx*2+1]);
}

int qry(int idx, int i, int j, int l, int r){
    if(i > r || j < l)
        return 0;
    if(i >= l && j <= r)
        return tree[idx];
    int m = (i + j)/2;
    return max(qry(idx*2, i, m, l, r),
            qry(idx*2+1, m+1, j, l, r));
}

bool valid(int i, int st){
    return (bst[st] >= qry(1, 0, n-1, i, i+st-1));
}

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        int mxd = 0;
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
            mxd = max(mxd, s[a]);
        }
        build(1, 0, n-1);
        scanf("%d", &m);
        for(int a=0;a<=n+1;a++)
            bst[a] = 0;
        for(int a=0;a<m;a++){
            int pwr, end;
            scanf("%d %d", &pwr, &end);
            bst[end] = max(pwr, bst[end]);
        }
        for(int a=n;a>0;a--)
            bst[a] = max(bst[a+1], bst[a]);
        if(bst[1] < mxd){
            puts("-1");
            continue;
        }
        int u = 0;
        int ans = 0;
        while(u < n){
            int i = u, j = n - 1;
            while(i < j){
                int m = (i + j + 1)/2;
                int st = m - u + 1;
                if(valid(u, st))
                    i = m;
                else
                    j = m-1;
            }
            u = i + 1;
            ans++;
        }
        printf("%d\n", ans);
    }
}
