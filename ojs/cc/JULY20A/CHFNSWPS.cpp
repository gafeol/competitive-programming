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
int s[2][MAXN];

map<int, int> cnt[3];

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        cnt[0].clear();
        cnt[1].clear();
        cnt[2].clear();
        int mn = INT_MAX;
        for(int i=0;i<2;i++){
            for(int a=0;a<n;a++){
                int x;
                scanf("%d", &x);
                mn = min(mn, x);
                cnt[i][x]++;
                cnt[2][x]++;
            }
        }
        int dif = 0;
        for(auto it: cnt[2]){
            if(it.snd&1){
                dif = -1;
                break;
            }
            dif += max(0, (cnt[0][it.fst] - cnt[1][it.fst])/2);
        }
        if(dif == -1){
            puts("-1");
            continue;
        }
        ll ans = 0;
        for(auto it: cnt[2]){
            if(it.snd&1){
                ans = -1;
                break;
            }
            int q = abs(cnt[0][it.fst] - cnt[1][it.fst])/2;
            ll usa = min(q, dif);
            dif -= usa;
            ans += min(usa*it.fst, usa*mn*2);
        }
        printf("%lld\n", ans);
    }
}

