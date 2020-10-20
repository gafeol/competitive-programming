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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

int main (){
    for_tests(t, tt){
        int ans[3];
        memset(ans, 0, sizeof(ans));
        scanf("%d", &n);
        if(n%3 == 2){
            if(n == 2){
                puts("-1");
                continue;
            }
            n -= 5;
            ans[1]++;
        }
        if(n%3 == 1){
            if(n < 7){
                puts("-1");
                continue;
            }
            n -= 7;
            ans[2]++;
        }
        printf("%d %d %d\n", n/3, ans[1], ans[2]);
    }
}

