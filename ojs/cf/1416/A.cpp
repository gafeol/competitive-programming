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

const int MAXN = 312345;

int n, m, k;
int s[MAXN];
int pos[MAXN];
int mxDif[MAXN];

int ans[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        for(int a=0;a<=n;a++){
            ans[a] = INT_MAX;
            pos[a] = -1;
            mxDif[a] = 0;
        }
        vector<int> X;
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
            mxDif[s[a]] = max(mxDif[s[a]], a - pos[s[a]]);
            pos[s[a]] = a;
            X.pb(s[a]);
        }
        sort(X.begin(), X.end());
        X.erase(unique(X.begin(), X.end()), X.end());

        for(int x: X){
            mxDif[x] = max(mxDif[x], n-pos[x]); 
        }

        for(int x: X){
            int u = mxDif[x] - 1;
            ans[u] = min(ans[u], x);
        }
        for(int a=0;a<n;a++){
            if(a > 0)
                ans[a] = min(ans[a], ans[a-1]);
            if(ans[a] == INT_MAX)
                printf("-1 ");
            else
                printf("%d ", ans[a]);
        }
        puts("");
    }
}

