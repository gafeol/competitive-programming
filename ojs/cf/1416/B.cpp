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

const int MAXN = 212345;

int n, m, k;
ll s[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        ll sum = 0;
        for(int a=1;a<=n;a++){
            scanf("%lld", s+a);
            sum += s[a];
        }

        if(sum % n != 0){
            puts("-1");
            continue;
        }
        ll mean = sum/n;
        vector<tuple<int,  int, ll>> ans;
        for(int a=2;a<=n;a++){
            int res = s[a]%a;
            if(res != 0){
                ll falta = a - res;
                ans.pb({1, a, falta});
                s[1] -= falta;
                assert(s[1] >= 0);
                s[a] += falta;
            }
            assert(s[a]%a == 0);
            ans.pb({a, 1, s[a]/a});
            s[1] += s[a];
            s[a] = 0;
        }

        for(int a=2;a<=n;a++){
            ans.pb({1, a, mean});
            s[1] -= mean;
            assert(s[1] >= 0);
            s[a] += mean;
        }
        /*
        for(int a=1;a<=n;a++){
            assert(s[a] == mean);
        }
        */
        printf("%d\n", (int)ans.size());
        for(tuple<int, int, ll> tp: ans){
            int i, j;
            ll x;
            tie(i, j, x) = tp;
            printf("%d %d %lld\n", i, j, x);
        }

    }
}

