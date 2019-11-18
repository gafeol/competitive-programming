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

const int MAXN = 21234;
const int EPS = 10000;

int n, m, k;
pii s[MAXN];
int ind[MAXN];
set<pii> lin[MAXN], col[MAXN];

int v[MAXN], h[MAXN];

bool cmp(int a, int b){
    return s[a] < s[b];
}

void go(int u, vector<int>& ans){
    ans.pb(u);
    while(ans.size() < n){
        if(ans.size()%2)
            u = h[u]; 
        else
            u = v[u];
        ans.pb(u);
    }
}


int main (){
    int tt = 0;
    while(scanf("%d", &n) != EOF && n > 0){
        for(int a=0;a<MAXN;a++){
            lin[a].clear();
            col[a].clear();
        }
        for(int a=0;a<n;a++){
            ind[a] = a;
            int i, j;
            scanf("%d %d", &j, &i);
            i += EPS; j += EPS;
            s[a] = {i, j};
            lin[i].insert({j, a}); 
            col[j].insert({i, a}); 
        }
        for(int i=0;i<MAXN;i++){
            pii prev;
            bool link = false;
            for(pii p: lin[i]){
                if(link){
                    h[prev.snd] = p.snd;
                    h[p.snd] = prev.snd;
                }
                link ^= 1;
                prev = p;
            }
        }
        for(int j=0;j<MAXN;j++){
            pii prev;
            bool link = false;
            for(pii p: col[j]){
                if(link){
                    v[prev.snd] = p.snd;
                    v[p.snd] = prev.snd;
                }
                link ^= 1;
                prev = p;
            }
        }
        vector<int> ans;
        sort(ind, ind+n, cmp); 
        go(ind[0], ans);
        printf("Polygon #%d:", ++tt);
        for(int x: ans){
            printf(" %d", x+1);
        }
        puts("");
    }
}

