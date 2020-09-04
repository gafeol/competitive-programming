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

const int MAXN = 1123;

int n, m, k;
char s[MAXN];
char pal[MAXN];

int main (){
    scanf(" %s", s);
    scanf(" %s", pal);
    n = strlen(s);
    int np  = strlen(pal);
    int res = INT_MAX;
    for(int i=0;i<=n-np;i++){
        int ans = 0;
        for(int j=0;j<np;j++){
            ans += (s[i+j] != pal[j]);
        }
        res = min(res, ans);
    }
    printf("%d\n", res);
}

