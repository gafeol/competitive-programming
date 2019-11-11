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

map<int, int> pai;
map<int, int> sz;

vector<int> pri;
int mrk[1123456];

ll n, m, k;

int main (){
    int on;
	scanf("%lld", &n);
    on = n;
    vector<ll> div;

    for(int a=2;a<=1000000;a++){
        if(!mrk[a])
            pri.pb(a);
        for(long long b=a;b*a <= 1000000;b++)
            mrk[b*a] = 1; 
    }

    for(ll p: pri){
        if(n%p == 0){
            while(n%p == 0)
                n/=p;
            div.pb(p);
        }
    }
    if(n > 1)
        div.pb(n);

    if(div.size() == 1)
        printf("%lld\n", div[0]);
    else
        printf("%lld\n", 1ll); 
}

