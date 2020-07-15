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

const int MAXN = 1123456;

int n, m, k;
char s[MAXN];

int main (){
    for_tests(t, tt){
        scanf(" %s", s);
        n = strlen(s);
        int sum = 0;
        int need = 0;
        for(int a=0;a<n;a++){
            sum += 2*(s[a]=='+')-1; 
            need = max(need, -sum);
        }
        sum = 0;
        ll res = 0;
        ll has = need+1;
        ll tot = need+1;
        for(int a=0;a<n;a++){
            res += has; 
            //printf("a %d has %lld res %lld\n", a, has, res);
            sum += 2*(s[a]=='+')-1; 
            has = min(has, tot+sum);
        }
        printf("%lld\n", res);
    }
}

