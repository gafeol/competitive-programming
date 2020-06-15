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

const int MAXN = 2123;

int n, m, k;
char s[MAXN];

int main (){
    for_tests(t, tt){
        scanf(" %s", s);
        n = strlen(s);

        int res = INT_MAX;
        // 0000 1111
        for(int j=-1;j<=n;j++){
            int ans = 0;
            for(int i=0;i<j;i++){
                ans += (s[i] == '1'); 
            }
            for(int i = j+1;i<n;i++){
                ans += (s[i] == '0');
            }
            res = min(res, ans);
        }
        for(int j=-1;j<=n;j++){
            int ans = 0;
            for(int i=0;i<j;i++){
                ans += (s[i] == '0'); 
            }
            for(int i = j+1;i<n;i++){
                ans += (s[i] == '1');
            }
            res = min(res, ans);
        }
        printf("%d\n", res);
    }
}

