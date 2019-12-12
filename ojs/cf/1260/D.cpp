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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int ns, n, k, t;
int s[MAXN];
vector<tuple<int, int, int>> traps;

int move(int i, int j){
    return j - i;
}

bool go(int wst){
    debug("wst %d\n", wst);
    int tot = n+1;
    vector<pair<int, int>> tps;
    int mx = 0;
    for(tuple<int, int, int> tp : traps){
        int l, r, d;
        tie(l, r, d) = tp;
        if(d > wst && r > mx){
            tps.pb({l, r});
            mx = max(r, mx);
        }
    }

    int i =0;
    while(i < tps.size()){
        int j = i;
        while(j+1 < tps.size()){
            if(tps[j+1].fst > tps[j].snd + 1)
                break;
            j++;
        }
        tot += 2*move(tps[i].fst-1, tps[j].snd);
        i = j+1;
    }

    if(tot <= t)
        debug("deu tot %d\n", tot);
    else
        debug("NAO deu, tot %d\n", tot);
    return (tot <= t);
}

int main (){
	scanf("%d%d%d%d", &ns, &n, &k, &t);
	for(int a=1;a<=ns;a++){
        scanf("%d", s+a);
	}
    s[0] = INT_MAX;
    sort(s, s+ns+1, greater<int>());
    for(int a=0;a<k;a++){
        int i, j, q;
        scanf("%d%d%d", &i, &j, &q);
        traps.pb({i, j, q});
    }
    sort(traps.begin(), traps.end());

    int i = 0, j = ns;
    while(i < j){
        int m = (i + j + 1)/2;
        if(go(s[m]))
            i = m;
        else
            j = m-1;
    }
    printf("%d\n", i);
}

