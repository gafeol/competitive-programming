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
int s[MAXN];

int cntL[MAXN];

vector<pii> ans;

set<int> at[MAXN];

set<int> lw[4];

void add(int i, int j){
    ans.pb({i, j});
    lw[cntL[i]].erase(i);
    at[i].insert(j);
    cntL[i]++;
    lw[cntL[i]].insert(i);
}

int getL(int w){
    if(lw[w].empty()){
        puts("-1");
        exit(0);
    }
    return *lw[w].rbegin();
}

void block(int i){
    lw[cntL[i]].erase(i);
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
        lw[0].insert(a);
        scanf("%d", s+a);
	}
    for(int j=n;j>=1;j--){
        if(s[j] == 0)
            continue;
        if(s[j] == 1){
            add(getL(0), j);
        }
        else if(s[j] == 2){
            add(getL(1), j);         
        }
        else{
            int livre = getL(0);
            if(!lw[2].empty()){
                int oi = getL(2);
                assert(livre < oi);
                int oj = *at[oi].begin();
                assert(j < oj);
                add(livre, j);  
                add(livre, oj);
                block(oi);
            }
            else{
                int oi = getL(1);
                assert(livre < oi);
                int oj = *at[oi].begin();
                assert(j < oj);
                add(livre, j);  
                add(livre, oj);
                block(oi);
            }
        }
    }
    printf("%d\n", (int)ans.size());
    for(pii p: ans){
        printf("%d %d\n", p.fst, p.snd);
    }
}

