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
char s[MAXN];

map<int, int> cnt;

int main (){
    for_tests(t, tt){
        cnt.clear();
        scanf("%d%d", &n, &k);
        scanf(" %s", s);
        int bal = 0;
        int mn = 0, mx = 0;
        for(int i=0;i<n;i++){
            cnt[bal]++;
            bal += (s[i] == '0' ? 1 : -1);
            mn = min(mn, bal);
            mx = max(mx, bal);
        }

        if(bal == 0){
            printf("%d\n", (cnt[k] > 0 ? -1: 0)); 
            continue;
        }

        ll ans = 0;
        if(bal > 0){
            int b = 0;
            for(int i=0;i<n;i++){
                if((k - b)%bal == 0 && k >= b){
                    ans++;
                }
                b += (s[i] == '0' ? 1 : -1);
            }
        }
        else{
            int b = 0;
            for(int i=0;i<n;i++){
                if((b - k)%bal == 0 && k <= b){
                    ans++;
                }
                b += (s[i] == '0' ? 1 : -1);
            }
        }
        printf("%lld\n", ans);
    }
}

