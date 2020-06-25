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
pii s[MAXN];
int qtd[MAXN], saldo[MAXN];
int ind[MAXN];

pii val(int i){
    return {min(saldo[s[i].fst], saldo[s[i].snd]), max(saldo[s[i].fst], saldo[s[i].snd])};
}
int mx(int i){
    return max(qtd[s[i].fst], qtd[s[i].snd]);
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=1;a<=n;a++){
        scanf("%d", qtd+a);
        saldo[a] = qtd[a];
	}
    for(int a=0;a<m;a++){
        ind[a] = a;
        scanf("%d%d", &s[a].fst, &s[a].snd);
        saldo[s[a].fst]--;
        saldo[s[a].snd]--;
    }
    sort(ind, ind+m, [&](int a, int b) { return val(a) < val(b); });
    for(int aa=0;aa<m;aa++){
        int a = ind[aa];    
        printf("mx %d = %d \n", a, mx(a));
        if(mx(a) <= 0){
            puts("DEAD");
            return 0;
        }
        qtd[s[a].fst]--;
        qtd[s[a].snd]--;
    }
    puts("ALIVE");
    for(int a=0;a<m;a++){
        printf("%d%c", ind[a]+1, " \n"[a==m-1]);
    }
}

