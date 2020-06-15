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

int n[3], m, k[2];
ll s[3][MAXN];

int main (){
	scanf("%d%d%d%d%d", k, k+1, n, n+1, n+2);
    for(int t=0;t<3;t++){
        for(int a=0;a<n[t];a++){
            scanf("%lld", &s[t][a]);
        }
        sort(s[t], s[t]+n[t], greater<ll>());
    }
    multiset<int> app;
    ll som = 0;
    for(int t=0;t<2;t++){
        for(int a=0;a<k[t];a++){
            app.insert(s[t][a]); 
            som += s[t][a];
        }
    }
    for(int i=0;i<n[2];i++){
        if(s[2][i] > *app.begin()){
            som -= *app.begin();
            app.erase(app.begin());
            app.insert(s[2][i]);
            som += s[2][i];
        }
    }
    printf("%lld\n", som);
}

