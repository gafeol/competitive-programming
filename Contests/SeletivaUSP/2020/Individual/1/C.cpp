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

int main (){
    int tt = 1;
    while(scanf("%d", &n) != EOF && n >= 0){
        for(int a=0;a<n;a++)
            scanf("%d", s+a);
        vector<int> v[16];
        for(int bit=0;bit<16;bit++){
            for(int a=0;a<n;a++)
               v[bit].pb(s[a]%(1<<(bit+1))); 
            sort(v[bit].begin(), v[bit].end());
        }
        char c;
        ll del = 0;
        ll res = 0;
        while(scanf(" %c", &c) != EOF && c != 'E'){
            ll x;
            scanf("%lld", &x);
            if(c == 'Q'){
                int d = del%(1<<(x+1)); 
                int ans = lower_bound(v[x].begin(), v[x].end(), (1<<(x+1)) - d) 
                            - lower_bound(v[x].begin(), v[x].end(), (1<<x) - d)
                            + v[x].end()
                            - lower_bound(v[x].begin(), v[x].end(), (1<<(x+1)) + (1<<x) -d);
                debug("ans %d\n", ans);
                res += ans;
            }
            else{
                del += x;
                del %= (1<<16);
            }
        }
        printf("Case %d: %lld\n", tt++, res);
    }
}

