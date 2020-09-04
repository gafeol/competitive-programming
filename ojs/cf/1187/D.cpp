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

int n, m, k;
int s[MAXN];

queue<int> pos[MAXN];

int tree[MAXN*4];
void build(int idx, int i, int j){
    tree[idx] = INT_MAX;
    if(i == j){
        tree[idx] = s[i];
        return ;
    }
    int m = (i + j)/2;
    build(idx*2, i, m);
    build(idx*2+1, m+1, j);
    tree[idx] = min(tree[idx*2], tree[idx*2+1]);
}

void upd(int idx, int i, int j, int l, int x){
    if(i > l || j < l) return; 
    if(i == j){
        tree[idx] = x;
        return;
    }
    int m = (i + j)/2;
    upd(idx*2, i, m, l, x);
    upd(idx*2+1, m+1, j, l, x);
    tree[idx] = min(tree[idx*2], tree[idx*2+1]);
}

int qry(int idx, int i, int j, int l, int r){
    if(i > r || j < l)
        return INT_MAX;
    if(i>=  l && j <= r){
        return tree[idx];
    }
    int m = (i + j)/2;
    return min(qry(idx*2, i, m, l, r),
                qry(idx*2+1, m+1, j, l, r));
}

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        for(int a=0;a<=n;a++){
            while(!pos[a].empty())
                pos[a].pop();
        }
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
            pos[s[a]].push(a);
        }
        build(1, 0, n-1);
        bool ok = true;
        for(int a=0;a<n;a++){
            int x;
            scanf("%d", &x);
            if(pos[x].empty())
                ok = false;
            else{
                if(qry(1, 0, n-1, 0, pos[x].front())  < x){
                    //printf("qry %d %d < x %d\n", pos[x].front(), qry(1, 0, n-1, 0, pos[x].front()), x);
                    ok = false;
                }
                upd(1, 0, n-1, pos[x].front(), INT_MAX);
                pos[x].pop();
            }
        }
        if(ok)
            puts("YES");
        else
            puts("NO");
    }
}

