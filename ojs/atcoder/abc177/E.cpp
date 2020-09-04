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

const int MAXN = 1000056;


ll gcd(ll a, ll b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

int s[MAXN];
int n, m, k;
int mrk[MAXN];

int main (){
	scanf("%d", &n);
    ll gc = 0;
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        mrk[s[a]]++;
        gc = gcd(gc, s[a]);
	}
    if(gc > 1){
        puts("not coprime");
        return 0;
    }
    for(ll v=2;v<MAXN;v++){
        int cnt = 0;
        for(ll m=1;v*m<MAXN;m++){
            cnt += mrk[v*m]; 
        }
        if(cnt > 1){
            puts("setwise coprime");
            return 0;
        }
    }
    puts("pairwise coprime");
}

