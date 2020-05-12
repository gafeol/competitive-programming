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

const int MAXN = 212345;
const double EPS = 1e-6;

int n, m, k;
ll s[MAXN], t[MAXN];

int rep[MAXN];
ll sz[MAXN];
ll sum[MAXN];

int raiz(int u){
    if(rep[u] == u)
        return u;
    return rep[u] = raiz(rep[u]);
}

double pos(int id){
    raiz(id);
    return (double)sum[rep[id]]/sz[rep[id]];
}

void join(int i, int j){
    i = raiz(i);
    j = raiz(j);
    if(i == j) return ;

    if(sz[i] < sz[j])
        swap(i, j);

    rep[j] = i;
    sz[i] += sz[j];
    sum[i] += sum[j];
}

double go(ll *s){
    for(int a=0;a<n;a++){
        sz[a] = 1;
        sum[a] = s[a];
        rep[a] = a;
    }

    stack<int> st;
    for(int a=0;a<n;a++){
        while(!st.empty() && pos(st.top()) >= pos(a)){
            join(st.top(), a); 
            st.pop();
        }
        
        st.push(raiz(a));
    }

    double res = 0; 
    for(int a=0;a<n;a++){
        res += (pos(a) - s[a])*(pos(a) - s[a]); 
    }
    return res;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%lld %lld", s+a, t+a);
        rep[a] = a;
        sum[a] = s[a];
	}

    double ans = go(s) + go(t);
    printf("%.10f\n", ans);
}

