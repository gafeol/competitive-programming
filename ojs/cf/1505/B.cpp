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
int s[MAXN];

bool isroot(ll x){
    ll pot = x;
    while(pot < n){
        pot *= x;
    }
    return (pot == n);
}

int main (){
	scanf("%d", &n);
    if(n == 1)
        puts("1");
    else{
        for(int i=n-1;i>=2;i--){
            if(isroot(i)){
                printf("%d\n", i);
                return 0;
            }
        }
        printf("%d\n", (int)sqrt(n));
    }
    return 0;
}

