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

ll n, m, k, x, y;
int s[MAXN];

// extended euclid
ll gcd(ll a, ll b, ll &x, ll &y){
    if (a == 0){
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b%a, a, x1, y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return d;
}


bool join(ll &a, ll &n, ll b, ll m){ // joins two clauses
    // finds positive res such that res%n = a and res%m = b
    ll x, y;
    ll gc = gcd(n, m, x, y);
    if((a - b)%gc != 0 || (n == m && a != b))
        return false; // no solution

    ll lcm = (n/gc)*m;
    ll res = (a + x * (b - a)/gc % (m / gc) * n) % lcm; 
    res = (res + lcm)%lcm; // get a positive solution

    // preparing for the next step
    a = res;
    n = lcm;
    return true;
}

void normalize(vector<ll> &val, vector<ll> &md){
    for(int i=0;i<val.size();i++)
        val[i] = (val[i]%md[i] + md[i])%md[i];
}

ll crt(vector<ll> &val, vector<ll> &md){
    normalize(val, md);

    ll lval = val[0], lmd = md[0];
    for(int i=1;i<val.size();i++){
        if(!join(lval, lmd, val[i], md[i]))
            return -1; // failed!
    }
    return lval;
}

int main (){
    int vx, vy;
	scanf("%lld%lld%lld%lld%d%d", &n, &m, &x, &y, &vx, &vy);

    if(vx == 0){
        if(x == 0)
            printf("0 %lld\n",  (vy == 1 ? m : 0));
        else if(x == n)
            printf("%lld %lld\n",  n, (vy == 1 ? m : 0));
        else
            puts("-1");
        return 0;
    }
    if(vy == 0){
        if(y == 0)
            printf("%lld 0", (vx == 1 ? n : 0));
        else if(y == m)
            printf("%lld %lld", (vx == 1 ? n : 0), m);
        else
            puts("-1");
        return 0;
    }
    vector<ll> val, md;
    val.pb((vx == 1 ? n-x: x));
    md.pb(n);
    val.pb((vy == 1 ? m-y : y));
    md.pb(m);

    ll res = crt(val, md);
    if(res == -1){
        puts("-1");
    }
    else{
        bool left, bott;
        if(vx > 0)
            left = (((res+x)/n)%2 == 0);
        else
            left = (((res+n-x)/n)%2 == 1);

        if(vy > 0)
            bott = (((res+y)/m)%2 == 0);
        else
            bott = (((res + m - y)/m)%2 == 1);

        if(left)
            printf("0 ");
        else
            printf("%lld ", n);
        if(bott)
            printf("0\n");
        else
            printf("%lld\n", m);
    }
}

