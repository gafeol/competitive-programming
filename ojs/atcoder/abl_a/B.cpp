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

bool in (int x, int l, int r){
    return (x >= l && x <= r);
}

int main (){
    ll a, b, c, d;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    if(in(a, c, d) || in(b, c, d) || in(c, a, b) || in(d, a, b))
        puts("Yes");
    else
        puts("No");
}

