#include "bits/stdc++.h"
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

const int MAXN = 312345;

int n, m, k;
char s[MAXN];

int check(int j){
    for(int sz=1;j - sz*2 >= 0;sz++){
        if(s[j] == s[j-sz]  && s[j] == s[j-2*sz])
            return sz;
    }
    return 0;
}

int main (){
    scanf(" %s", s);
    n = strlen(s);
    ll ans = 0;
    int i = -1;
    for(int j=0;j<n;j++){
        int sz = check(j);
        if(sz){
            int ni = j-2*sz;
            i = max(i, ni);
        }
        ans += i + 1;
    }
    printf("%lld\n", ans);
}

