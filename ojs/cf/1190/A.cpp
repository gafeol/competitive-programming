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

ll n, k;
int m;
ll s[MAXN];

int main (){
	scanf("%lld%d%lld", &n, &m, &k);
	for(int a=0;a<m;a++){
        scanf("%lld", s+a);
        s[a]--;
	}

    int i = 0;
    ll off = 0;
    int res = 0;
    while(i < m){
        int cnt = 1;
        while(i + 1 < m && (s[i+1] - off)/k == (s[i] - off)/k){
            i++;
            cnt++;
        }
        res++;
        off += cnt;
        i++;
    }
    printf("%d\n", res);
}

