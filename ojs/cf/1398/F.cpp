#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

const int MAXN = 1000006;

int n, m, k;
char s[MAXN];
int lg[2][MAXN];
vector<int> x[MAXN];
set<int> ind;
set<int>::iterator it;

int main (){
	scanf("%d\n", &n);
	for(int a=0;a<n;a++){
        s[a] = getchar();
        ind.insert(a);
	}
    if(s[n-1] == '0'){
        lg[0][n-1] = 1;
        lg[1][n-1] = 0;
    }
    else if(s[n-1] == '1'){
        lg[0][n-1] = 0;
        lg[1][n-1] = 1;
    }
    else
        lg[0][n-1] = lg[1][n-1] = 1;

    x[max(lg[0][n-1], lg[1][n-1])].pb(n-1);

    for(int a=n-2;a>=0;a--){
        lg[0][a] = lg[1][a] = 0;
        if(s[a] != '1')
            lg[0][a] = 1 + lg[0][a+1];
        if(s[a] != '0')
            lg[1][a] = 1 + lg[1][a+1];
        x[max(lg[0][a], lg[1][a])].pb(a);
    }
    for(int sz=1;sz<=n;sz++){
        int u = 0;
        int ans = 0;
        while(!ind.empty() && u < n && (it = ind.lower_bound(u)) != ind.end()){
            int tam = max(lg[0][*it], lg[1][*it]);
            ans+=tam/sz;
            u = *it + (tam/sz)*sz;
        }
        printf("%d ", ans);
        for(int i: x[sz])
            ind.erase(i);
    }
    puts("");
}

