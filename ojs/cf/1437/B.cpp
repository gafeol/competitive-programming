#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define eb emplace_back
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
char s[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        scanf(" %s", s);
        int res = 0;
        int ans = 0;
        int lstW = -2;
        for(int a=0;a<n;a++){
            int w = (a&1);
            if(w != s[a]-'0'){
                ans += (lstW < a-1);
                lstW = a;
            }
        }
        res = ans;
        ans = 0;
        lstW = -2;
        for(int a=0;a<n;a++){
            int w = !(a&1);
            if(w != s[a]-'0'){
                ans += (lstW < a-1);
                lstW = a;
            }
        }
        res = min(res, ans);

        printf("%d\n", res);
    }
    return 0;
}

