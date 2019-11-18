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

ll n, m, k;

int main (){
	scanf("%lld", &n);
    if(n == 0){
        puts("0");
        return 0;
    }
    if(n == 1){
        puts("1");
        return 0;
    }
    vector<ll> d;
    while(n%9 == 0){
        d.pb(9);
        n/=9;
    }
    while(n%8==0){
        d.pb(8);
        n/=8;
    }
    while(n%6==0){
        d.pb(6);
        n/=6;
    }
    while(n%4==0){
        d.pb(4);
        n/=4;
    }
    for(ll a=2;a*a < n;a++){
        while(n%a == 0){
            d.pb(a);
            n/=a;
        }
    }
    if(n > 1)
        d.pb(n);
    sort(d.begin(), d.end());
    if(d.back() >= 10){
        puts("-1");
        return 0;
    }
    for(int i=0;i<d.size();i++){
        int x = d[i];
        printf("%d", x);
    }
    puts("");
}
