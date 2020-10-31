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
ll s[MAXN];
ll ss[MAXN];

bool eq(){
    for(int a=0;a<n;a++){
        if(s[a] != ss[a])
            return false;
    }
    return true;
}

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        vector<ll> x;
        for(int a=0;a<n;a++){
            scanf("%lld", s+a);
            x.pb(s[a]);
        }
        sort(x.begin(), x.end());
        x.erase(unique(x.begin(), x.end()), x.end());
        for(int a=0;a<n;a++)
            s[a] = (lower_bound(x.begin(), x.end(), s[a]) - x.begin());
        sort(s, s+n);
        scanf("%d", &m);
        vector<ll> xx;
        for(int a=0;a<m;a++){
            scanf("%lld", ss+a);
            xx.pb(ss[a]);
        }
        if(n != m){
            puts("NO");
            continue;
        }

        sort(xx.begin(), xx.end());
        xx.erase(unique(xx.begin(), xx.end()), xx.end());
        for(int a=0;a<n;a++)
            ss[a] = lower_bound(xx.begin(), xx.end(), ss[a]) - xx.begin();
        sort(ss, ss+n);

        if(eq()){
            puts("YES");
            continue;
        }
        for(int a=0;a<n;a++)
            ss[a] = xx.size() -1 - ss[a];
        reverse(ss, ss+n);
        if(eq())
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}

