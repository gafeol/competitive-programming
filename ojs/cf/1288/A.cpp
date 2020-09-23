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

const int MAXN = 1123456;

ll n, m, k;

int main (){
    for_tests(t, tt){
        scanf("%lld%lld", &n, &m);
        ll bst = LLONG_MAX;
        bool ok = false;
        for(int a=0;a<MAXN;a++){
            bst = min(bst, a + (a+m)/(a+1));
            if(bst <= n){
                ok = true;
                break;
            }
        }
        if(ok)
            puts("YES");
        else
            puts("NO");
    }
}

