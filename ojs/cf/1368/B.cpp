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

ll n, m, k;

ll expo(ll base, ll e){
    if(e == 0)
        return 1ll;

    ll ans = expo(base, e/2);
    ans = ans*ans;
    if(e&1)
        ans = base*ans;
    return ans;
}

int main (){
	scanf("%lld", &n);
    string cf = "codeforces";

    ll rep = 1;
    while(expo(rep, 10) < n)
        rep++;
    ll ans = 1;
    for(int i=0;i<cf.size();i++){
        char c = cf[i];
        while(rep > 1 && expo(rep-1, cf.size()-i)*ans >= n)
            rep--;
        ans *= rep;
        for(int a=0;a<rep;a++){
            printf("%c", c);
        }
    }
    puts("");
}

