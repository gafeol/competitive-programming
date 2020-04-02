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

int n;
ll k;
ll s[MAXN];
bool mrk[60];

ll pot[60];

int main (){
    for_tests(t, tt){
        memset(mrk, false, sizeof(mrk));
        scanf("%d%lld", &n, &k);
        int mx = 0;
        pot[0] = 1;
        ll val = 1;
        for(mx=1;log(val) + log(k) < log(10000000000000000LL) + 2;mx++){
            val *= k;  
            pot[mx] = val;
        }
        bool ok = true;
        for(int a=0;a<n;a++){
            scanf("%lld", s+a);
            for(int i=mx-1;ok && i>=0;i--){
                if(mrk[i])
                    continue;
                if(s[a] >= pot[i]){
                    s[a] -= pot[i];
                    mrk[i] = true;
                }
            }
            if(s[a] != 0)
                ok = false;
        }
        if(ok)
            puts("YES");

        else
            puts("NO");
    }
}

