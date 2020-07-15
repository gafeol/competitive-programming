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

int mrk[MAXN];
vector<int> pri;
int main (){
    for(int a=2;a<MAXN;a++){
        if(mrk[a]) continue;
        pri.pb(a);
        for(ll b=a;a*b<MAXN;b++){
            mrk[a*b] = 1;
        }
    }
    for_tests(t, tt){
        scanf("%d", &n); 
        ll val[] = {1, 1};
        bool ok = false;
        for(int p: pri){
            if(n%p == 0){
                //printf("p %d\n", p);
                ok = true;
                val[0] = n/p;     
                val[1] = (n/p)*(p-1);
                break;
            }
        }
        if(!ok){
            val[0] = 1;
            val[1] = n-1;
        }
        printf("%lld %lld\n", val[0], val[1]);

    }
}

