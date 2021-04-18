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

int n, m, k;

set<pii> q;

void seta(int x){
    if(x <= 0 || x >= n+1) return ;
    int val = INT_MAX;
    auto it = q.lower_bound({x, -1});
    if(it != q.end()){
        auto [y, cus] = *it;
        val = min(val, cus + abs(x - y));
    }
    if(it != q.begin()){
        it--;
        auto [y, cus] = *it;
        val = min(val, cus + abs(x - y));
    }
    if(val != INT_MAX)
        q.insert({x, val});
}

void apaga(int de, int ate){
    auto it = q.lower_bound({de, -1});
    while(it != q.end() && it->fst <= ate){
        auto prv = it;
        it++;
        q.erase(prv);
    }
}


int main (){
	scanf("%d%d%d", &n, &m, &k);
    q.insert({k, 0});
	for(int a=0;a<m;a++){
        int t, l, r;
        scanf("%d %d %d", &t, &l, &r);
        if(t == 1){
            seta(l-1);
            seta(r+1);
            apaga(l, r);
        }
        else{
            seta(l);
            seta(r);
            apaga(1, l-1);
            apaga(r+1, n);
        }
	}
    if(q.empty())
        puts("-1");
    else{
        int mn = INT_MAX;
        for(auto [x, c]: q){
            mn = min(mn, c);
        }
        printf("%d\n", mn);
    }
    return 0;
}

