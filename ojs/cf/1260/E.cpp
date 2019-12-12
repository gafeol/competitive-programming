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

const int MAXN = 2123456;

int n, m, k;
ll s[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%lld", s+a);
	}
    int j = n-1;
    int step = n/2;
    ll ans = 0;
    multiset<ll> q;
    for(int i=n-1;i>=j;i--){
        if(s[i] == -1)
            break;
        q.insert(s[i]);
        if(i == j){
            ans += *q.begin();
            q.erase(q.begin());
            j -= step;
            step /= 2;
        }
    }
    printf("%lld\n", ans);
}

