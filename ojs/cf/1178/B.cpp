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

const int MAXN = 1123456;

int n, m, k;
char s[MAXN];
int cnt[MAXN];

int main (){
    scanf(" %s", s);
    n = strlen(s);
    char nxt = '0';
    for(int a=n-1;a>=0;a--){
        cnt[a] = cnt[a+1];
        if(s[a] == 'v') {
            if(nxt == 'v'){
                cnt[a]++;
            }
        }
        nxt = s[a];
    }
    ll res = 0;
    int nw = 0;
    char bef = '0';
    for(int i=0;i<n;i++){
        if(s[i] == 'v'){
            if(bef == 'v')
                nw++;
        }
        else{
            res += ((ll)cnt[i])*((ll)nw);
        }
        bef = s[i];
    }
    printf("%lld\n", res);
}

