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
int s[MAXN];

int main (){
	scanf("%d", &n);
    vector<int> div;
    for(int a=1;a<=n;a++){
        if(n%a == 0){
            div.pb(a);
        }
    }
    ll ans = LLONG_MAX;
    for(int i=0;i<div.size();i++){
        for(int j=0;j<div.size();j++){
            ll x = div[i], y = div[j];
            if((n/x)%y == 0){
                ll z = (n/x)/y;
                ans = min(ans, x*y*2 + x*z*2 + y*z*2); 
            }
        }
    }
    printf("%lld\n", ans);
}

