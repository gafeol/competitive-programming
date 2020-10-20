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

const int MAXN = 500005;

int n, m, k, del;

char f[MAXN];
int tam[MAXN];

vector<int> pos[MAXN];
int deg[MAXN];

int prox(int t){
    if(deg[t] == pos[t].size())
        return n;
    return pos[t][deg[t]];
}

int main (){
	scanf("%d", &n);
    int cnt = 0, MX = 0;
    ll sum = 0;
	for(int a=0;a<n;a++){
        scanf(" %c", f+a);
        if(f[a] == '0')
            cnt = 0;
        else
            cnt++;
        pos[cnt].push_back(a);
        MX = max(MX, cnt);
        sum += MX;
	}
    for(int a=n-1;a>=0;a--){
        if(f[a] == '0')
            tam[a] = 0;
        else
            tam[a] = tam[a+1] + 1;
    }
    ll res = 0;
    for(int a=0;a<n;a++){
        res += sum;
        if(f[a] == '0')
            continue;
        //debug("apaga a pos %d de tam %d\n", pos[tam[a]].front(), tam[a]);
        deg[tam[a]]++;
        //pos[tam[a]].pop_front();
        //debug("retira 1 de todos de %d ate %d-1\n", a, prox(tam[a]));
        sum -= prox(tam[a]) - a;
    }
    printf("%lld\n", res);
}
 
