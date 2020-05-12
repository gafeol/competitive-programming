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

const int MAXN = 412345;

int n, m, k;
int s[MAXN];
int v[MAXN];

int main (){
	scanf("%d", &n);
    for(int a=0;a<n;a++){
        scanf("%d", v+a);
    }
    int res = 0;
    for(int i=0;i<=24;i++){
        ll cnt = 0;
        for(int a=0;a<n;a++){
            s[a] = v[a]%(1<<(i+1));
        }
        sort(s, s+n);
        for(int a=1;a<n;a++){
            int x = (1<<i) - s[a];
            int y = (1<<(i+1)) - s[a];
            int z = (1<<(i+1)) + (1<<i) - s[a];
            cnt += lower_bound(s, s+a, y) - lower_bound(s, s+a, x) + lower_bound(s, s+a, z) - s+a;
        }
        if(cnt&1)
            res += (1<<i);
    }
    printf("%d\n", res);

}

