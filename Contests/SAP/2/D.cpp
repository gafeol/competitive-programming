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

int go(int u, int ini){
    if(s[u] == ini) return 0;
    return 1 + go(s[u], ini);
}

int main (){
	scanf("%d%d", &n, &m);
    for(int a=1;a<=n;a++)
        s[a] = a;
	for(int a=0;a<m;a++){
        int t;
        scanf("%d", &t);
        if(t == 1){
            int i, j;
            scanf("%d%d", &i, &j);
            swap(s[i], s[j]);
        }
        else{
            int i;
            scanf("%d", &i);
            printf("%d\n", go(i, i));
        }
	}
}

