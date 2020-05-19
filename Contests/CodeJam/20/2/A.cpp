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


ll sz[2];
ll ans;

ll client;

inline ll sum(ll q){
    return ((2ll*client + q -1)*q)/2ll;
}

inline void mkge(int t){
    if(sz[t] - client < sz[t^1])
        return;
    ll dif = sz[t] - sz[t^1];
    ll del = client*client + 8ll*dif;
    ll sq = sqrt(del);
    ll q = (-client + sq)/2ll;
    for(ll qq = q+1;qq>=q-1;qq--){
        ll s = sum(qq);
        if(sz[t] - s >= sz[t^1]){
            client += qq;
            sz[t] -= s;
            return ;
        }
    }

}

inline void dim(){
    int t = (sz[0] >= sz[1] ? 0 : 1);
    ll i = 1, j = sqrt(2ll*sz[t^1]) + 10; // checar i
    if(sz[t^1] - client -1 < 0) return ;
    while(i < j){
        ll m = (i + j + 1)/2ll;
        ll ns[2]; 
        ns[t] = sz[t] - (m*(client + client + 2*(m-1)))/2ll;   
        ns[t^1] = sz[t^1] - (m*(client + 1 + client + 1 + 2*(m-1)))/2ll;
        //debug("m %lld ns %lld %lld\n", m, ns[t], ns[t^1]);
        if(min(ns[t], ns[t^1]) < 0)
            j = m - 1;
        else if(ns[t] < ns[t^1])
            j = m - 1;
        else
            i = m;
    }

    //debug("dim szs %lld %lld i %lld cl %lld\n", sz[0], sz[1], i, client);
    sz[t] = sz[t] - (i*(client + client + 2*(i-1)))/2ll;   
    sz[t^1] = sz[t^1] - (i*(client + 1 + client + 1 + 2*(i-1)))/2ll;
    client += i*2;
    //debug("aft szs %lld %lld i %lld cl %lld\n", sz[0], sz[1], i, client);
}

inline void eq(){
    mkge(0);
    mkge(1); 
    while(1){
        int t = (sz[0] >= sz[1] ? 0 : 1);
        if(sz[t] - client >= 0){
            sz[t] -= client;
            client++;
        }
        else
            break;
        dim();
    }

}


int main (){
    for_tests(t, tt){
        client = 1;
        scanf("%lld%lld", sz, sz+1);
        eq(); 
        printf("Case #%d: %lld %lld %lld\n", tt, client-1, sz[0], sz[1]);
    }
}

