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

const int MAXN = 212345;

int n, m, k;
ll st[MAXN];

ll nt[MAXN];
int cnt[MAXN];

void add(int i){
    if(cnt[i] == 0)
        k++;
    cnt[i]++;
}

void rmv(int i){
    if(cnt[i] == 1)
        k--;
    cnt[i]--;
}


bool check(){
    return (k == n);
}

int main (){
    for(int a=0;a<6;a++){
        scanf("%lld", st+a);
    }
	scanf("%d", &n);
    map<ll, vector<int>> ev;
	for(int a=0;a<n;a++){
        scanf("%lld", nt+a);
        for(int c=0;c<6;c++){
            ev[nt[a] - st[c]].pb(a);
        }
	}
    k = 0;

    auto i = ev.begin();
    auto j = ev.begin();
    for(int id: j->snd)
        add(id);
    ll ans = LLONG_MAX;
    while(1){
        while(!check()){
            j++;
            if(j == ev.end())
                break;
            for(int id: j->snd)
                add(id);
        }
        if(!check())
            break;
        ans = min(ans, j->fst - i->fst);
        //printf("ans  em i %lld j %lld\n", i->fst, j->fst);
        for(int id: i->snd)
            rmv(id);
        i++;
    }
    printf("%lld\n", ans);
    return 0;
}

