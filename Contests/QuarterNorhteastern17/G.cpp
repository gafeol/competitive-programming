#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

const int MAXN = 55;

int n;
int s[MAXN];
map<ll, map<ll, int>> dp[MAXN][MAXN];

int gcd(int a,int b){
    if(a == 0) return b;
    return gcd(b%a, a);
}


int go(int i, int j, int vi, int vj){
    if(dp[i][j][vi].find(vj) != dp[i][j][vi].end())
        return dp[i][j][vi][vj];
    int &r = dp[i][j][vi][vj];
    r = 0;
    map<int, int> cnt;
    for(int k=i;k<j;k++){
        int vk = (k == i ? vi: s[k]);
        int vkk = (k+1 == j ? vj : s[k+1]);
        int gc = gcd(vk, vkk);
        if(gc > 1){
            int val = (go(i, k, vi, vk/gc) ^ go(k+1, j, vkk/gc, vj));
            if(val <= 50){
                cnt[val] = 1;
            }
        }
    }
    for(int a=0;a<=50;a++){
        if(cnt[a] == 0){
            r = a;
            //printf("i %d j %d v %d %d: %d\n", i, j, vi, vj, r);
            return r;
        }
    }
    return r;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
	}
    if(go(0, n-1, s[0], s[n-1]))
        puts("Alice");
    else
        puts("Bob");

    return 0;
}
