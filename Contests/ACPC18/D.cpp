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

ll n, m;
int k;

map<int, int> cnt;
map<int, map<int, int>> M;
int main (){
    freopen("dull.in", "r", stdin);// NAO MANDAR FILHO DA PUTA
    for_tests(t, tt){
        M.clear();
        cnt.clear();
        scanf("%lld%lld%d", &n, &m, &k);
        for(int a=0;a<k;a++){
            int i, j;
            scanf("%d%d", &i, &j);
            M[i][j]++;
        }
        ll bef = 0;
        ll odd = 0;
        ll ans = 0;
        for(auto it: M){
            int i = it.fst;
            //debug("no i %d\nans %lld\n", i, ans);
            ans += odd*(i - bef); 
            ll bl = 0;
            for(auto lin: it.snd){
                int j = lin.fst;
                cnt[j]+=lin.snd; 
            }
            int q = 0;  
            int lst = 0;
            odd = 0;
            for(auto u: cnt){
                if(q&1)
                    odd += (u.fst - lst);
                q += u.snd;
                lst = u.fst;
            }
            if(q&1)
                odd += m - lst + 1;
            //debug("ans pos lin %lld\n", ans);
            //debug("odd %lld\n", odd);
            bef = it.fst;
        }
        ans += odd*(n - bef + 1);
        printf("%lld %lld\n", ans, n*m - ans);
    }
}

