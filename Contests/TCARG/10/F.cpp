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

ll n, m, k;
int main (){
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);
	scanf("%lld", &n);
    if(n == 1){
        puts("WIN");
        return 0;
    }
    ll lose = 2;
    ll step = 1;
    while(lose <= n){
        //printf("lose %lld st %lld\n", lose, step);
        if(lose == n){
            puts("LOSE");
            return 0;
        }
        while(lose + step + 1 >= (step+1)*(step+1))
            step++;
        lose += step+1;
    }
    puts("WIN");
}

