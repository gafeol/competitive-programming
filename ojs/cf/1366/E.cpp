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
const ll modn = 998244353;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
int s[MAXN];
int v[MAXN];
int ate[MAXN];
int de[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
	}
    for(int b=0;b<m;b++){
        scanf("%d", v+b);
        ate[b] = 0;
    }
    v[m] = INT_MAX;

    memset(de, -1, sizeof(de));
    for(int a=0;a<n;a++){
        int i = upper_bound(v, v+m+1, s[a]) - v;
        if(i == 0){
            puts("0");
            return 0;
        }
        ate[i-1] = max(ate[i-1], a);

        i = lower_bound(v, v+m+1, s[a]) - v;
        if(s[a] == v[i])
            de[i] = max(de[i], a);
    }
    for(int a=0;a<m;a++){
        if(de[a] == -1){
            puts("0");
            return 0;
        }
        ate[a] = max(ate[a], de[a]);
    }
    ll ans =1;
    for(int i=0;i+1<m;i++){
        if(ate[i] >= de[i+1]){
            puts("0");
            return 0;
        }
        ans = mod(ans*(de[i+1] - ate[i]));
    }
    printf("%lld\n", ans);
}

