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

const int MAXN = 1123456;

int n, m, k;
ll s[MAXN];
ll sum[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<(n+1)/2;a++){
        scanf("%lld", s+a);
    }
    ll x;
    scanf("%lld", &x);
    for(int a=(n+1)/2;a<n;a++){
        s[a] = x;
    }
    int k = (n+1)/2;
    ll pref = 0;
    for(int i=0;i<k;i++){
        pref += s[i];
    }
    multiset<ll> q;
    vector<ll> adds;
    ll aux = 0;
    q.insert(0ll);
    adds.pb(0);
    for(int i=k;i<n;i++){
        aux += s[i] - s[i-k]; 
        q.insert(aux);
        adds.pb(aux);
    }
    while(k <= n){
        //printf("k %d pref %lld men %lld\n", k, pref, *q.begin());
        if(pref + *q.begin() > 0){
            printf("%d\n", k);
            return 0;
        }
        pref += s[k];
        q.erase(q.find(adds.back()));
        adds.pop_back();
        k++;
    }
    puts("-1");
}

