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

const int MAXN = 212345;

int n, m, k;
inline ll mod(ll x) { return x % m; }
int s[MAXN];

map<int, bool> mrk;

int main (){
	scanf("%d%d", &n, &m);
    bool z = false;
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        if(mrk.find((s[a]%m)) != mrk.end())
            z = true;
        mrk[(s[a]%m)] = true;
	}
    if(z){
        puts("0");
        return 0;
    }
    ll ans = 1;
    for(int a=0;a<n;a++){
        for(int b=a+1;b<n;b++){
            ans = mod(ans*mod(abs(s[b] - s[a])));
        }
    }
    printf("%lld\n", ans);
}

