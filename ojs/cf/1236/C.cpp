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

const int MAXN = 312;

int n, m, k;
vector<int> v[MAXN];

int main (){
	scanf("%d", &n);
    int cnt;
    for(int a=0;a<n*n;a++){
        int t = a/n;
        int i;
        if(t%2 == 0)
            i = (a%n) + 1;
        else
            i = n - (a%n);
        v[i].pb(a+1);
    }
    for(int a=1;a<=n;a++){
        for(int x=0;x<v[a].size();x++){
            int val = v[a][x];
            printf("%d ", val);
        }
        puts("");
    }
}

