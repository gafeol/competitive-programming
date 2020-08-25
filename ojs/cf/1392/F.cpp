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

const int MAXN = 2123456;

ll n, m, k;
ll s[MAXN];
int main (){
	scanf("%lld", &n);
    ll sum = 0;
	for(int a=0;a<n;a++){
        scanf("%lld", s+a);
        sum += s[a];
	}
    if((2*sum)%n == 0 && ((2*sum)/n - n + 1)%2 == 0){
        ll x = ((2*sum)/n - n + 1)/2;
        for(int a=0;a<n;a++){
            printf("%lld ", x+a);
        }
        puts("");
        return 0;
    }
    for(ll i=0;i+1<n;i++){
        ll num = 2*sum - (n-i-1)*(n-i-2) + i*i + i;
        if(num%(2*n) == 0){
            ll x = num/(2*n);
            for(int a=0;a<i;a++){
                printf("%lld ", x - (i - a)); 
            }
            printf("%lld %lld ", x, x);
            for(int a=i+2;a<n;a++){
                printf("%lld ", x+(a - i-1));
            }
        }
    }
    puts("");
}

