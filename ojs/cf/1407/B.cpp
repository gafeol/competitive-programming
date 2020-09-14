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

int n, m, k;
int s[MAXN];
int ind[MAXN];
int o[MAXN];

int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
            o[a] = s[a];
            ind[a] = a;
        }
        sort(ind, ind+n, [&](int a, int b) { return s[a] > s[b]; });
        for(int i=0;i<n;i++){
            printf("%d ", o[ind[i]]);
            int gc = s[ind[i]];
            for(int j=i+1;j<n;j++){
                s[ind[j]] = gcd(s[ind[j]], gc);
            }
            sort(ind+i+1, ind+n, [&](int a, int b) { return s[a] > s[b]; });
        }
        puts("");
    }
}

