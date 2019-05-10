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

const int MAXN = 112345;

int n, m, k;
int s[MAXN];
int v[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &k);
        for(int i=0;i<n;i++)
            scanf("%d", s+i);
        for(int i=0;i<n;i++)
            scanf("%d", v+i);
        long long res = 0;
        for(int i=0;i<n;i++){
            int mxs = INT_MIN, mxv = INT_MIN;
            for(int j = i;j < n;j++){
               mxs = max(mxs, s[j]);
               mxv = max(mxv, v[j]);
               if(abs(mxs - mxv) <= k){
                   res++;
               }
            }
        }
        printf("Case #%d: %lld\n", tt, res);
    }
}

