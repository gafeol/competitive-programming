#include "bits/stdc++.h"
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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        int ans = n;
        vector<pii> res;
        for(int i=n-1;i>=1;i--){
            res.pb({i, ans});
            ans = (ans + i + 1)/2;
        }
        printf("%d\n", ans);
        for(int i=0;i<res.size();i++){
            printf("%d %d\n", res[i].fst, res[i].snd);
        }
    }
}

