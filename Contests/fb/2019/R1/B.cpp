// Two pointers
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

const int MAXN = 1000006;

int n, m, k;
char s[MAXN];
ll pot[MAXN];

int main (){
    pot[0] = 1;
    for(int a=1;a<MAXN;a++)
        pot[a] = mod(pot[a-1]*2ll);
    for_tests(t, tt){
        long long ans = 0;
        scanf("%d %d", &n, &k);
        int sum = 0, j = n-1;
        scanf(" %s", s);
        for(int a=n-1;a>=0;a--){
            char c = s[a];
            if(c == 'B')
                sum++;
            else
                sum--;

            if(sum > k){
                ans = mod(ans + pot[a+1]);
                sum -= 2;
            }

            if(sum <= 0){
                j = a-1;
                sum = 0;
            }
        }
        printf("Case #%d: ", tt);
        printf("%lld\n", ans);
    }
}

